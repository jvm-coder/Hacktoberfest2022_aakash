from turtle import Turtle
START_POSITIONS = [(0,0),(-20,0),(-40,0)]
MOVE_DISTANCE = 20
UP = 90
DOWN = 270
LEFT = 180
RIGHT = 0
class Snake():
    def __init__(self) -> None:
        self.snake = []
        self.create_snake()
        self.head = self.snake[0]

    def create_snake(self):
        for pos_num in START_POSITIONS:
            segment = Turtle(shape="square")
            segment.penup()
            segment.goto(pos_num)
            segment.color("white")
            self.snake.append(segment)
    
    def up(self):
        if self.snake[0].heading() != DOWN:
            self.snake[0].setheading(UP)
    
    def down(self):
        if self.snake[0].heading() != UP:
            self.snake[0].setheading(DOWN)

    def left(self):
        if self.snake[0].heading() != RIGHT:
            self.snake[0].setheading(LEFT)
    
    def right(self):
        if self.snake[0].heading() != LEFT:
            self.snake[0].setheading(RIGHT)    

    def move(self):
        for seg_num in range(len(self.snake)-1,0,-1):
            x_cor = self.snake[seg_num-1].xcor()
            y_cor = self.snake[seg_num-1].ycor()
            self.snake[seg_num].goto(x_cor,y_cor)
        self.snake[0].forward(MOVE_DISTANCE)
    

    def collision_wall(self):
        if self.head.xcor() > 280 or self.head.xcor() < -280 or self.head.ycor() > 280 or self.head.ycor() < -280:
            return True
    
    def collision_body(self):
        for segment in self.snake[1:]:
            if self.head.distance(segment) < 10:
                return True
    
    def new_segment(self):
        position = self.snake[-1].pos()
        segment = Turtle(shape="square")
        segment.penup()
        segment.goto(position)
        segment.color("white")
        self.snake.append(segment)
    
    def reset(self):
        for segment in self.snake:
            segment.goto(1000,1000)
        self.snake.clear()
        self.create_snake()
        self.head = self.snake[0]