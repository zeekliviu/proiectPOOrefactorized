######### Importing Libraries #########

import sys
from fpdf import FPDF # necesita install
from datetime import datetime
import locale
import qrcode # necesita install
import ssl, smtplib # necesita install
import cryptocode as cc # necesita install

from email import encoders
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.header import Header
from email.utils import formataddr
#######################################

######### Setting Locale ##############

locale.setlocale(locale.LC_ALL, 'ro_RO.UTF-8')

#######################################

######### initializare pdf #########

pdf = FPDF('P', 'mm', (127, 127))
pdf.add_page()

####################################

######### adaugare fonturi #########

pdf.add_font('MSSansSerif', '', './micross.ttf', uni=True)
pdf.add_font('Cascadia', '', './CascadiaMonoLight.ttf', uni=True)

######### adaugare fonturi #########

######### desenare margini #########
pdf.set_draw_color(106, 32, 192)
pdf.set_line_width(3)
pdf.line(0, 127, 127, 127)
pdf.line(0, 0, 127, 0)
pdf.line(0, 0, 0, 127)
pdf.line(127, 0, 127, 127)

####################################

######### adaugare logo #########

pdf.image("logo.png", w=60, h=60, x=75, y=-10)
pdf.image("zeth.png", x=-10, y=94.5, w=60, h=30)

####################################

######### adaugare header #########

pdf.set_font('MSSansSerif', '', 20)
pdf.cell(0, 10, "BILET", 0, 1, 'L')
pdf.cell(0, 10, "EVENIMENT", 0, 1, 'L')
pdf.set_line_width(1)
pdf.line(12, 35, 117, 35)

####################################

######### body bilet #########

EVENIMENT = sys.argv[1]
DATA = sys.argv[2]
ORA = sys.argv[3]
LOCAȚIE = sys.argv[4]
ZONA = sys.argv[5]
RAND = sys.argv[6]
LOC = sys.argv[7]
UID = sys.argv[8]
QRCODE_UID = qrcode.make(UID)
QRCODE_UID.save(f"qrcode{UID}.png")
DATA_DT = datetime.strptime(DATA, "%d/%m/%Y").strftime("%A %d %B %Y")

pdf.set_font('Cascadia', '', 12)
pdf.cell(0, 25, "EVENIMENT " + EVENIMENT, 0, 1, 'L')
pdf.cell(0, -15, DATA_DT + " " + ORA, 0, 1, 'L')
pdf.cell(0, 25, LOCAȚIE, 0, 1, 'L')

pdf.line(12, 60, 117, 60)
pdf.set_font('Cascadia', '', 15)
pdf.cell(0, 0, "ZONA: " + ZONA, 0, 1, 'L')
pdf.cell(0, 15, f"RAND: {RAND}", 0, 1, 'L')
pdf.cell(0, 0, f"LOC: {LOC}", 0, 1, 'L')
pdf.image(f"qrcode{UID}.png", w=28, h=28, x=85, y=62)
pdf.line(12, 90, 117, 90)

pdf.set_font('Cascadia', '', 12)
pdf.cell(0, 26.5, "UID: " + UID, 0, 1, 'C')
##############################

######### output #########

pdf.output(f"bilet_{UID}.pdf")

##########################

######### email #########

subject = "🎫 Biletul tău la evenimentul " + EVENIMENT
body = "Bună ziua, \n\nAtașat găsiți biletul dumneavoastră la evenimentul " + EVENIMENT + " din data de " + DATA_DT +\
       " la ora " + ORA + ".\n\nVă mulțumim pentru că ați ales să participați la evenimentul nostru!\n\nCu stimă," \
                          "\nEchipa Zeth Tickets"
sender_email = cc.decrypt(sys.argv[9], sys.argv[12])
password = cc.decrypt(sys.argv[10], sys.argv[12])
receiver_email = sys.argv[11]

message = MIMEMultipart()
message["From"] = formataddr((str(Header('Zeth Tickets', 'utf-8')), sender_email))
message["To"] = receiver_email
message["Subject"] = subject
message.attach(MIMEText(body, "plain"))

filename = f"bilet_{UID}.pdf"

with open(filename, "rb") as attachment:
    part = MIMEBase("application", "octet-stream")
    part.set_payload(attachment.read())

encoders.encode_base64(part)

part.add_header(
    "Content-Disposition",
    f"attachment; filename= {filename}",
)

message.attach(part)
text = message.as_string()

context = ssl.create_default_context()
with smtplib.SMTP_SSL("smtp.hostinger.com", 465, context=context) as server:
    server.login(sender_email, password)
    server.sendmail(sender_email, receiver_email, text)