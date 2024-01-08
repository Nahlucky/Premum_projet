import py5
import time
import random
from moduleSnake import *
  
game_paused = 0

deplacement = 4
size = 10

pos_x1 = random.randrange(10, 400, size)
pos_y1 = random.randrange(10, 300, size)

pos_x2 = pos_x1 - size
pos_y2 = pos_y1

pos_x3 = pos_x1 - (size * 2)
pos_y3 = pos_y1

pos_x4 = pos_x1 - (size * 3)
pos_y4 = pos_y1

circle1 = Generator(pos_x1, pos_y1)
circle2 = Generator(pos_x2, pos_y1)
circle3 = Generator(pos_x3, pos_y1)
circle4 = Generator(pos_x4, pos_y1)

body = [circle1, circle2, circle3, circle4]

snake = Snake(body)

def setup():
    global wall, food

    py5.size(800, 600)
    
    wall = py5.load_image("src/mur-gris.png")
    food = py5.load_image("src/pomme.png")

def draw():
    global deplacement, game_paused, circle1
    gen = Generator()
    FOUND = 1
    TRUE   = 1
    FALSE  = 0
    
    py5.background(0, 0, 0)
    gen.draw_arena(wall)
    gen.draw_food(food)
    
    if game_paused == FALSE:
        if Snake.ALIVE == TRUE:
            
            Snake.direction = deplacement
            snake.move()
            snake.find_food()
            if Snake.food == FOUND:
                snake.grow()
                gen.change_food_pos()
    
        elif Snake.ALIVE == FALSE:
            snake.gameover()

    elif game_paused == TRUE:
        snake.pause()
        
                 
    time.sleep(0.01)

def key_pressed():
    global deplacement, ancien_depl, game_paused
    BACKSPACE = ' '

    if py5.key == py5.CODED:
        if py5.key_code == py5.UP:
            deplacement = 1
        elif py5.key_code == py5.DOWN:
            deplacement = 2
        elif py5.key_code == py5.LEFT:
            deplacement = 3
        elif py5.key_code == py5.RIGHT:
            deplacement = 4
    if py5.is_key_pressed:
        if py5.key == BACKSPACE and game_paused == 0:
            game_paused = 1
        elif py5.key == BACKSPACE and game_paused == 1:
            game_paused = 0
        
py5.run_sketch()

