
from os import close
from turtle import Turtle
ALIGNMENT = "center"
FONT = ("Arial",14,"normal")

class Scoreboard(Turtle):
    def __init__(self):
        super().__init__()
        self.penup()
        self.color("white")
        self.hideturtle()
        self.goto(x=0,y=280)
        self.score = 0
        with open("D:\programming\python_\project 20-snake game\data.txt",mode='r') as data:
            self.highscore = int(data.read())
        self.print_score()
        self.speed("fastest")

    def print_score(self):
        self.clear()
        self.write(f"Score: {self.score} HighScore: {self.highscore}",False,align=ALIGNMENT,font=FONT)
    
    def increment_score(self):
        self.score += 1 

    
    def reset(self):
        if self.score > self.highscore:
            self.highscore = self.score
            with open("project 20-snake game\data.txt",mode='w') as data:
                data.write(str(self.highscore))
            
        self.score = 0
        self.print_score()


    

    
