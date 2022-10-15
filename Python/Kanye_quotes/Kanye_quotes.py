from tkinter import *
import requests


window =Tk()
window.title("Kanye Quotes")
window.config(pady=50, padx=50)


#--------------Quote-------------------#
def quotes():
    response = requests.get(url="https://api.kanye.rest")
    data = response.json()["quote"]
    print(data)
    canvas.itemconfig(card_title, text=data)


canvas = Canvas(width=300, height=414)


image = PhotoImage(file="background.png")
card = canvas.create_image(150, 207, image=image)
card_title = canvas.create_text(150, 207, text="Tital",width=250, font=("Ariel", 20, "italic"))

canvas.grid(row=0,column=0)


#button

kanye_image = PhotoImage(file="kanye.png")
kanye_button = Button(image=kanye_image, highlightthickness=0, command=quotes )
kanye_button.grid(row=1,column=0)

window.mainloop()

