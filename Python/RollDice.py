import random
import tkinter

root = tkinter.Tk()
root.geometry('600x600')
root.title('Roll Dice')

#label to print result
label = tkinter.Label(root, text='', font=('Helvetica', 260))

#label to introduce
label2 = tkinter.Label(root, text='Welcome to Dice roll. Click to roll dice ', font=('Helvetica',10))
label2.place(x=150,y=400)

def roll_dice():
    value = ['\u2680', '\u2681', '\u2682', '\u2683', '\u2684', '\u2685']
    result=random.choice(value)
    label.configure(text=result)
    label.pack()
    if(result=='\u2680'):
        label3=tkinter.Label(root,text='You rolled a one! Click roll dice to roll again.',font=('Helvetica',10))
        label3.place(x=150,y=450)
    elif(result=='\u2681'):
        label3=tkinter.Label(root,text='You rolled a two! Click roll dice to roll again.',font=('Helvetica',10))
        label3.place(x=150,y=450)
    elif(result=='\u2682'):
        label3=tkinter.Label(root,text='You rolled a three! Click roll dice to roll again.',font=('Helvetica',10))
        label3.place(x=150,y=450)
    elif(result=='\u2683'):
        label3=tkinter.Label(root,text='You rolled a four! Click roll dice to roll again.',font=('Helvetica',10))
        label3.place(x=150,y=450)
    elif(result=='\u2684'):
        label3=tkinter.Label(root,text='You rolled a five! Click roll dice to roll again.',font=('Helvetica',10))
        label3.place(x=150,y=450)
    elif(result=='\u2685'):
        label3=tkinter.Label(root,text='You rolled a six! Click roll dice to roll again.',font=('Helvetica',10))
        label3.place(x=150,y=450)
button = tkinter.Button(root, text='roll dice', foreground='red', command=roll_dice)
button.pack()
root.mainloop()

