from turtle import Turtle , Screen, clear, forward

tom = Turtle()
screen = Screen()

def moveForward():
    tom.forward(15)

def moveBackward():
    tom.backward(15)

def moveRight():
    tom.right(10)

def moveLeft():
    tom.left(10)

def clear():
    tom.clear()
    tom.penup()
    tom.home()
    tom.pendown()

screen.listen()
screen.onkey(key = "w", fun = moveForward)
screen.onkey(key = "s", fun = moveBackward)
screen.onkey(key = "a", fun = moveRight)
screen.onkey(key = "d", fun = moveLeft)
screen.onkey(key = "c", fun = clear)










screen.exitonclick()