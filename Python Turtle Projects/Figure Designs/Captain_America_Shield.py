import turtle
import math

t = turtle.Turtle()


def ankur(x, y):
    t.penup()
    t.goto(x, y)
    t.pendown()
    t.setheading(0)
    t.pensize(2)
    t.speed(10)


def golo(r, color):
    x_point = 0
    y_pont = -r
    ankur(x_point, y_pont)
    t.pencolor(color)
    t.fillcolor(color)
    t.begin_fill()
    t.circle(r)
    t.end_fill()


def paanch(r, color):
    ankur(0, 0)
    t.pencolor(color)
    t.setheading(162)
    t.forward(r)
    t.setheading(0)
    t.fillcolor(color)
    t.begin_fill()
    for i in range(5):
        t.forward(math.cos(math.radians(18)) * 2 * r)  # 2cos18°*r
        t.right(144)
    t.end_fill()
    t.hideturtle()


if __name__ == '__main__':
    golo(288, 'crimson')
    golo(234, 'snow')
    golo(174, 'crimson')
    golo(114, 'blue')
    paanch(114, 'snow')
    turtle.done()