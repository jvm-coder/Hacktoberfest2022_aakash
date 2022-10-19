import pdfkit

str = input("Enter link to convert to pdf.: ")
name = input("Enter filename: ")

pdfkit.from_url(str, name)