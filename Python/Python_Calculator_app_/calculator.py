#/usr/bin/python3.7
import math
from tkinter import *

root = Tk() 
root.title("Calculator")
root.configure(bg='#40E0D0')

operator = ""
equation = StringVar()
calculation = Label(root,textvariable = equation)
equation.set("Enter here!")

calculation.grid(columnspan = 4)
def btnpress(num):
	global operator
	operator=operator+str(num)
	equation.set(operator)

def btnclear():
	global operator
	operator = ""
	equation.set("")

def btneqs():
	global operator
	evall = str(eval(operator))
	equation.set(evall)

Button0 = Button(root,text="0",bg='#0052cc',fg='#ffffff',bd=30,font='arial',command = lambda:btnpress(0))
Button0.grid(row = 1, column = 0)
Button1 = Button(root,text="1",bg='#0052cc',fg='#ffffff',bd=30,font='arial',command = lambda:btnpress(1))
Button1.grid(row = 1, column = 1)
Button2 = Button(root,text="2",bg='#0052cc',fg='#ffffff',bd=30,font='arial',command = lambda:btnpress(2))
Button2.grid(row = 1, column = 2)
Button3 = Button(root,text="3",bg='#0052cc',fg='#ffffff',bd=30,font='arial',command = lambda:btnpress(3))
Button3.grid(row = 2, column = 0)
Button4 = Button(root,text="4",bg='#0052cc',fg='#ffffff',bd=30,font='arial',command = lambda:btnpress(4))
Button4.grid(row = 2, column = 0)
Button5 = Button(root,text="5",bg='#0052cc',fg='#ffffff',bd=30,font='arial',command = lambda:btnpress(5))
Button5.grid(row = 2, column = 1)
Button6 = Button(root,text="6",bg='#0052cc',fg='#ffffff',bd=30,font='arial',command = lambda:btnpress(6))
Button6.grid(row = 2, column = 2)
Button7 = Button(root,text="7",bg='#0052cc',fg='#ffffff',bd=30,font='arial',command = lambda:btnpress(7))
Button7.grid(row = 3, column = 0)
Button8 = Button(root,text="8",bg='#0052cc',fg='#ffffff',bd=30,font='arial',command = lambda:btnpress(8))
Button3.grid(row = 3, column = 1)
Button9 = Button(root,text="9",bg='#0052cc',fg='#ffffff',bd=30,font='arial',command = lambda:btnpress(9))
Button9.grid(row = 3, column = 2)
plus = Button(root,text="+",bg='#0052cc',fg='#ffffff',bd=30,font='arial',command = lambda:btnpress("+"))
plus.grid(row = 1,column =3)
minus = Button(root,text="-",bg='#0052cc',fg='#ffffff',bd=30,font='arial',command = lambda:btnpress("-"))
minus.grid(row = 2,column =3)
mult= Button(root,text="*",bg='#0052cc',fg='#ffffff',bd=30,font='arial',command = lambda:btnpress("*"))
mult.grid(row = 3,column =3)
divd = Button(root,text="/",bg='#0052cc',fg='#ffffff',bd=30,font='arial',command = lambda:btnpress("/"))
divd.grid(row = 4,column =3)
equ = Button(root,text="=",bg='#0052cc',fg='#ffffff',bd=30,font='arial',command = btneqs)
equ.grid(row = 4,column =2)
clear = Button(root,text="C",bg='#0052cc',fg='#ffffff',bd=30,font='arial',command = btnclear)
clear.grid(row = 4,column =0)

root.mainloop()
