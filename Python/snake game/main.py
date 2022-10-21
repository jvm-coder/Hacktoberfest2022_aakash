from turtle import Screen
import time
from snake import Snake
from food import Food
from scoreboard import Scoreboard
screen = Screen()
screen.setup(width=600,height=600)
screen.bgcolor("black")
screen.tracer(0)

snake = Snake()
food = Food()
scoreboard = Scoreboard()

screen.listen()
screen.onkey(fun=snake.up,key="Up")
screen.onkey(fun=snake.down,key="Down")
screen.onkey(fun=snake.right,key="Right")
screen.onkey(fun=snake.left,key="Left")


while True:
    screen.update()
    time.sleep(0.1)
    snake.move()
    
    if snake.head.distance(food) < 15 :
        food.refresh()
        snake.new_segment()
        scoreboard.increment_score()
    
    scoreboard.print_score()
    
    if snake.collision_wall() or snake.collision_body():
        scoreboard.reset()
        snake.reset()
    
    