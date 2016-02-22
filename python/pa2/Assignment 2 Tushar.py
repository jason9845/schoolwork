"""
COMP1021    Turtle Graphics - Game Programming
Tushar JAIN
20142361
tjain@connect.ust.hk

"""

import turtle
import random
import time
import pygame

pygame.init()
pygame.mixer.init(buffer=16)
bg_music = pygame.mixer.Sound('insects.wav')
gameover_sound = pygame.mixer.Sound('apple_bite.wav')

"""
    Constants and variables
"""
# Part 1
# Set up constants and variables

# Window size
window_height = 600
window_width = 600

# The screen update interval
update_interval = 25

# Parameters for controlling the width of the river
river_width = 300
minimum_river_width = 70

# Border parameters
border_height = 600

# Parameters for gradually decreasing river width
river_width_update = 0.5

# How far should we stay away from the borders
safe_distance_from_border = border_height / 2 + 3

# Parameters for crocodiles
croc_number = ((2*10)+3+6+1)//2
crocs = []
croc_speeds = []
croc_width = 100
croc_height = 40
croc_speed_min, croc_speed_max = 3, ((2*10)+3+6+1)//2

# How far should we stay away from the crocodiles
safe_distance_from_croc = 15

# Score
z = 0
score = turtle.Turtle()
score.hideturtle()
score.up()
score.color("white")
score.goto(240, 250)

"""
    Helper function and event handler functions
"""

# Part 6
# Show a message when the game ends
def gameover(msg):
    bg_music.stop()
    gameover_sound.play()
    turtle.home()
    turtle.pencolor("white")
    turtle.write(msg, align="center", font=("Arial", 24, "normal"))


def moveplayerturtle(x, y):
    # Allow the turtle to move within the window only
    if x > -window_width / 2 and x < window_width / 2:
        turtle.goto(x, y)
        
def updatescreen():
    """
        This function does:
            1. Decrease the width of the river
            2. Check if the player has won the game
            3. Check if the player has hit the borders
            4. Move the crocodiles
            5. Check if the player has collided with a crocodile
            6. Update the screen
            7. Schedule the next update
    """
    
    # Global variables that will be changed in the function
    global river_width
    global z
    global score
    global river_width_update
    
    # Part 4.2
    # Decrease the width of the river by river_width_update
    upper_river_border.sety(upper_river_border.ycor() - river_width_update)
    lower_river_border.sety(lower_river_border.ycor() + river_width_update)
    river_width = river_width - river_width_update * 2

    # Part 4.3
    # 4.3.1 Check if the minimum river width has been reached
    if river_width <= minimum_river_width:
        river_width_update = 0

    # 4.3.2 Check if the player has hit the borders
    # The vertical distance between the player's turtle and the 
    # borders must be large enough, otherwise the player loses
    # the game
    if upper_river_border.ycor() - turtle.ycor() < safe_distance_from_border:
        gameover("Too bad! The apple is inedible!\nYour final score was " + str(z))
        return
    if turtle.ycor() - lower_river_border.ycor() < safe_distance_from_border:
        gameover("Too bad! The apple is inedible!\nYour final score was " + str(z))
        return

    # Part 5.2
    # Move the crocodiles
    # For every crocodile in crocodiles
    for i in range(croc_number):
        # 5.2.1. Move the crocodile to the left
        crocs[i].forward(croc_speeds[i])
        
        # 5.2.2. If the crocodile moves out of the screen, move it 
        #    to the right hand side and generate its speed and
        #    position randomly
        #    Also, update the score at this point
    score.down()
    score.clear()
    score.write("Score: " + str(z), font=("Arial", 18, "bold"), align="center")
    for i in range(croc_number):
        if crocs[i].xcor() < -(window_width+croc_width)/2:
            x = (window_width+croc_width)/2
            y = random.uniform(-(river_width-croc_height)/2, (river_width-croc_height)/2) # random y position within the two river borders
            crocs[i].goto(x, y)
            croc_speeds[i] = random.randint(croc_speed_min, croc_speed_max) # random speed value
            z += croc_number*2 + 2*croc_speeds[i]
        # Part 5.3
        # Check collision
        if turtle.distance(crocs[i]) < safe_distance_from_croc:
            gameover("Too bad! The apple is inedible!\nYour final score was " + str(z))
            return
    
    # Part 3 (3-4 of 4)
    # 3.3. Update the screen
    turtle.update()
    # 3.4. Schedule an update in 'update_interval' milliseconds
    turtle.ontimer(updatescreen, update_interval)

"""
    Here is the entry point of the game
    
    First of all, we create turtles for each component
    in the game with turtle.Turtle().
    The components are:
        1. The player turtle
        2. Two big boxes used as borders of the river
        3. Ten crocodiles
    
    Then we set up the event handlers for:
        1. The ondrag handler to handle the player's control
        2. The ontimer handler to handle timer event for 
           regular screen update

    After all the components are ready, start the game
"""
# Part 1
turtle.setup(window_width, window_height) # Set the window size
turtle.bgcolor("springgreen")

# Part 3 (1 of 4)
# 3.1. Turn off the tracer here
turtle.tracer(False)

# Part 5.1
# Add the crocodile image to the pool of shapes
turtle.addshape("worm.gif")

# Create crocodiles
for _ in range(((2*10)+4+2+3+6+1)):

    # a. Create a new turtle instance which is facing left
    croc = turtle.Turtle()

    # b. Set the shape
    croc.shape("worm.gif")

    # c. Rotate the crocodile
    croc.left(180)
    
    # d. Place the crocodile in the right hand side randomly
    croc.up()
    x = (window_width + croc_width) / 2
    y = random.uniform(-(river_width-croc_height)/2, (river_width-croc_height)/2)
    croc.goto(x, y)

    # e. Add the new crocodile to the list 'crocs'
    crocs.append(croc)

# Part 4.1
# 4.1.1. Create the big boxes for upper border and lower border
# 4.1.2. Set the shape of the borders
# 4.1.3. Set the colour of the borders
upper_river_border = turtle.Turtle()
turtle.addshape("upper_river_border.gif")
upper_river_border.shape("upper_river_border.gif")
upper_river_border.up()
lower_river_border = turtle.Turtle()
turtle.addshape("lower_river_border.gif")
lower_river_border.shape("lower_river_border.gif")
lower_river_border.up()

# 4.1.4. Set the size of the borders
upper_river_border.shapesize(30, 40)
lower_river_border.shapesize(30, 40)

# 4.1.5. Set the initial y position of the borders
upper_river_border.sety((border_height + river_width) / 2)
lower_river_border.sety(-(border_height + river_width) / 2)

# Prepare the player turtle
turtle.addshape("apple.gif")
turtle.shape("apple.gif")
turtle.up()

label_turtle = turtle.Turtle()
label_turtle.hideturtle()
label_turtle.pencolor("white")
label_turtle.up()
label_turtle.goto(-120, 100) # Put the text next to the spinner control
label_turtle.write("Maximum Speed of Worms:", font=("Arial", 10, "bold"))

speed_text = turtle.Turtle()
speed_text.hideturtle()
speed_text.pencolor("white")
speed_text.up()
speed_text.goto(70, 100) # Put the text next to the spinner control
speed_text.write(str(croc_speed_max), align = "center")

left_arrow = turtle.Turtle()
left_arrow.shape("arrow")
left_arrow.color("white")
left_arrow.shapesize(0.5, 1)
left_arrow.left(180)
left_arrow.up()
left_arrow.goto(50, 105)

def decrease_speed(x, y):
    global croc_speed_max, croc_speed_min
    if croc_speed_max > croc_speed_min + 1:
        croc_speed_max = croc_speed_max - 1
        speed_text.clear()
        speed_text.write(str(croc_speed_max), align = "center")
left_arrow.onclick(decrease_speed)

right_arrow = turtle.Turtle()
right_arrow.shape("arrow")
right_arrow.color("white")
right_arrow.shapesize(0.5, 1)
right_arrow.up()
right_arrow.goto(90, 105)

def increase_speed(x, y):
    global croc_speed_max, croc_speed_min
    if croc_speed_max < ((2*10)+4+2+3+6+1):
        croc_speed_max = croc_speed_max + 1
        speed_text.clear()
        speed_text.write(str(croc_speed_max), align = "center")        
right_arrow.onclick(increase_speed)

label_turtle_number = turtle.Turtle()
label_turtle_number.hideturtle()
label_turtle_number.pencolor("white")
label_turtle_number.up()
label_turtle_number.goto(-120, 80) # Put the text next to the spinner control
label_turtle_number.write("Maximum Number of Worms:", font=("Arial", 10, "bold"))

number_text = turtle.Turtle()
number_text.hideturtle()
number_text.pencolor("white")
number_text.up()
number_text.goto(70, 80) # Put the text next to the spinner control
number_text.write(str(croc_number), align = "center")

left_arrow_number = turtle.Turtle()
left_arrow_number.shape("arrow")
left_arrow_number.color("white")
left_arrow_number.shapesize(0.5, 1)
left_arrow_number.left(180)
left_arrow_number.up()
left_arrow_number.goto(50, 85)

def decrease_crocodile(x, y):
    global croc_number
    if croc_number > 4:
        croc_number = croc_number - 1
        number_text.clear()
        number_text.write(str(croc_number), align = "center")
left_arrow_number.onclick(decrease_crocodile)

right_arrow_number = turtle.Turtle()
right_arrow_number.shape("arrow")
right_arrow_number.color("white")
right_arrow_number.shapesize(0.5, 1)
right_arrow_number.up()
right_arrow_number.goto(90, 85)

def increase_crocodile(x, y):
    global croc_number
    if croc_number < ((2*10)+4+2+3+6+1):
        croc_number = croc_number + 1
        number_text.clear()
        number_text.write(str(croc_number), align = "center")        
right_arrow_number.onclick(increase_crocodile)

start_button = turtle.Turtle()
start_button.up()
start_button.goto(-40, 45)
start_button.color("black")
start_button.begin_fill()
for _ in range(2):
    start_button.forward(80)
    start_button.left(90)
    start_button.forward(25)
    start_button.left(90)
start_button.end_fill()

start_button.color("white")
start_button.goto(0, 50)
start_button.write("Start", font=("Arial", 10, "bold"), align="center")
start_button.goto(0, 58)
start_button.shape("square")
start_button.shapesize(1.25, 4)
start_button.color("")

title_text = turtle.Turtle()
title_text.hideturtle()
title_text.up()
title_text.goto(0,250)
title_text.color("white")
title_text.down()
title_text.write("Save the Apple!", font=("Arial", 30, "bold"), align="center")

info_text = turtle.Turtle()
info_text.hideturtle()
info_text.color("white")
info_text.up()
info_text.goto(0, 235)
info_text.down()
info_text.write("Please choose the number and speed of the worms.", font=("Arial", 15, "bold"), align="center")
info_text.up()
info_text.goto(0, 220)
info_text.down()
info_text.write("Please press the Start button to start the game.", font=("Arial", 15, "bold"), align="center")
info_text.up()
info_text.goto(0, 205)
info_text.down()
info_text.write("You need to drag the apple to save it from the worms.", font=("Arial", 15, "bold"), align="center")
info_text.up()
info_text.goto(0, 190)
info_text.down()
info_text.write("The apple will become inedible if it touches the worm or a boundry.", font=("Arial", 15, "bold"), align="center")

def startgame(x, y):
    # Part 2 (1 of 2)
    # 2.1 Set up event handlers
    # Set up the ondrag event of the turtle
    # Part 2 (2 of 2)
    # 2.2 Event handler for the turtle.ondrag() event
    turtle.ondrag(moveplayerturtle)
    time.sleep(1)
    bg_music.play()
    # Part 3 (2 of 4)
    # Set up the timer to run update_screen
    # 3.2. Schedule the first update
    # It starts the main loop and starts the game
    # Event handler for the turtle.ontimer() event
    turtle.ontimer(updatescreen, update_interval)
    # Set up the initial speed values of the crocodiles
    # 5.1.2. Generate a random speed and store it in 'croc_speeds'
    for _ in range(croc_number):
        croc_speeds.append(random.uniform(croc_speed_min, croc_speed_max))
    # Remove GUI components
    label_turtle.clear()
    label_turtle.hideturtle()
    speed_text.clear()
    speed_text.hideturtle()
    left_arrow.clear()
    left_arrow.hideturtle()
    right_arrow.clear()
    right_arrow.hideturtle()
    label_turtle_number.clear()
    label_turtle_number.hideturtle()
    number_text.clear()
    number_text.hideturtle()
    left_arrow_number.clear()
    left_arrow_number.hideturtle()
    right_arrow_number.clear()
    right_arrow_number.hideturtle()
    start_button.clear()
    start_button.hideturtle()
    title_text.clear()
    title_text.hideturtle()
    info_text.clear()
    info_text.hideturtle()
    
# Start the main loop, start the game
start_button.onclick(startgame)
turtle.update()
turtle.done()
