
def Cppsecrets (python , cplusplus):
    if python >0:
        turtle.forward(python)
        turtle.right(cplusplus)
        Cppsecrets(python-5,cplusplus)
import turtle
turtle.shape('turtle')
turtle.reset()
turtle.pen(speed =1)
turtle.delay(0)
length =400
turn_by =121
turtle.penup()
turtle.setpos(-length/2,length/2)
turtle.pendown()
Cppsecrets(length,turn_by)
