import requests
from bs4 import BeautifulSoup
import random # for random quotes
import time
from tkinter import *

# host and headers
HOST = 'https://r6.tracker.network/'
HEADERS = {
	'accept':'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
	'user-agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.88 Safari/537.36'
}

# function to get html response
def get_html(url):
	r = requests.get(url, headers=HEADERS)
	return r.text

# function to get content from r6.tracking
def get_content(html):
	soup = BeautifulSoup(html, 'html.parser')
	try:
		k_d = soup.find_all('div', {'class':'trn-defstat__value', 'data-stat':'PVPKDRatio'})[0].decode_contents().strip()
		w_r = soup.find_all('div', {'class':'trn-defstat__value', 'data-stat':'PVPWLRatio'})[0].decode_contents().strip()
		h_s = soup.find_all('div', {'class':'trn-defstat__value', 'data-stat':'PVPAccuracy'})[0].decode_contents().strip()
		t_p = soup.find_all('div', {'class':'trn-defstat__value', 'data-stat':'PVPTimePlayed'})[0].decode_contents().strip()
	except IndexError:
		return None
	stats = {
		'K/D':k_d,
		'W/R':w_r,
		'HS':h_s,
		'TP':t_p
	}
	return stats

# function to get random quotes from the file
def get_quote():
	file = open('Python/RainbowSixSiegeTracker/files/quotes.txt',  encoding = 'utf-8')
	lines = file.readlines()
	time.sleep(0.001)
	quote = lines[random.randrange(len(lines))].rstrip()
	return quote

# main function
def main():
	URL = HOST + 'profile/pc/' + enterfield.get()
	html = get_html(URL)
	if get_content(html):
		global label_wr_val
		global label_kd_val
		global label_hs_val
		global label_tm_val
		global label_quote
		label_wr_val.destroy()
		label_kd_val.destroy()
		label_hs_val.destroy()
		label_tm_val.destroy()
		label_quote.destroy()
		label_wr_val = Label(root, text=get_content(html).get('W/R'))
		label_kd_val = Label(root, text=get_content(html).get('K/D'))
		label_hs_val = Label(root, text=get_content(html).get('HS'))
		label_tm_val = Label(root, text=get_content(html).get('TP'))
		label_wr_val.grid(row=2, column=1)
		label_kd_val.grid(row=2, column=3)
		label_hs_val.grid(row=3, column=3)
		label_tm_val.grid(row=3, column=1)
		label_quote = Label(root, text=get_quote(), wraplength=300)
		label_quote.grid(row=4, column=0, columnspan=4, pady=20)

# making window with icon and title
root = Tk()
root.title('R6 tracker')
root.iconbitmap('Python/RainbowSixSiegeTracker/files/icon.ico')

# defining elements of gui
label1 = Label(root, text="Enter your nickname:")
enterfield = Entry(root, width=40)
button = Button(root, text="Search", command=main)
label_wr_def = Label(root, text='W/R: ')
label_wr_val = Label(root, text=' - ')
label_kd_def = Label(root, text='K/D: ')
label_kd_val = Label(root, text=' - ')
label_tm_def = Label(root, text='Time played: ')
label_tm_val = Label(root, text=' - ')
label_hs_def = Label(root, text='Headshot %: ')
label_hs_val = Label(root, text=' - ')
label_quote = Label(root, text=get_quote(), wraplength=300)
label_autor = Label(root, text='Made by HunterS')
label_sourse = Label(root, text='Info from r6.tracker.network')

# placing elements on the right place
label1.grid(row=0, column=0, columnspan=4, pady=5)
enterfield.grid(row=1, column=0, columnspan=3, padx=20, pady=5)
button.grid(row=1, column=3, padx=20, pady=20)
label_wr_def.grid(row=2, column=0)
label_wr_val.grid(row=2, column=1)
label_kd_def.grid(row=2, column=2)
label_kd_val.grid(row=2, column=3)
label_tm_def.grid(row=3, column=0)
label_tm_val.grid(row=3, column=1)
label_hs_def.grid(row=3, column=2)
label_hs_val.grid(row=3, column=3)
label_quote.grid(row=4, column=0, columnspan=4, pady=20)
label_autor.grid(row=5, column=0, columnspan=2)
label_sourse.grid(row=5, column=2, columnspan=2)

# main loop of our program
root.resizable(False, False)
root.mainloop()