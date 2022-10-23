
from tkinter import colorchooser
import pygame
from network import Network
import pickle

pygame.font.init() #initiatise the font module

width = 1000
height = 900
win = pygame.display.set_mode((width, height)) #display the gui window
pygame.display.set_caption("Rock Paper Scissor Game")#text on the top of the gui


class Button:
    def __init__(self, text, x, y, color):
        self.text = text
        self.x = x
        self.y = y
        self.color = color
        self.width = 150
        self.height = 100

    def draw(self, win):
        pygame.draw.rect(win, self.color, (self.x, self.y, self.width, self.height))
        font = pygame.font.SysFont("lucid-bold", 40)
        text = font.render(self.text, 1, (255,255,255))
        win.blit(text, (self.x + round(self.width/2) - round(text.get_width()/2), self.y + round(self.height/2) - round(text.get_height()/2)))

    def click(self, pos):
        x1 = pos[0]
        y1 = pos[1]
        if self.x <= x1 <= self.x + self.width and self.y <= y1 <= self.y + self.height:
            return True
        else:
            return False


def redrawWindow(win, game, p):
    win.fill((0,191,255))

    if not(game.connected()):
        font = pygame.font.SysFont("lucid-bold", 80)
        text = font.render("Waiting for Player...", 1, (255,255,255), True)
        win.blit(text, (width/2 - text.get_width()/2, height/2 - text.get_height()/2))
    else:
        font = pygame.font.SysFont("lucid-bold", 60)
        text = font.render("Your Move", 1, (255,255,255))
        win.blit(text, (180, 200))

        text = font.render("Opponents Move", 1, (255, 255, 255))
        win.blit(text, (440, 200))

        move1 = game.get_player_move(0) #called fun which is in game.py
        move2 = game.get_player_move(1) #called fun which is in game.py
        if game.bothWent():
            text1 = font.render(move1, 1, (255,99,71))
            text2 = font.render(move2, 1, (255, 99, 71))
        else:
            if game.p1Went and p == 0:
                text1 = font.render(move1, 1, (255,99,71))
            elif game.p1Went:
                text1 = font.render("Locked In", 1, (255, 255, 255))
            else:
                text1 = font.render("Waiting...", 1, (255, 255, 255))

            if game.p2Went and p == 1:
                text2 = font.render(move2, 1, (255,255,255))
            elif game.p2Went:
                text2 = font.render("Locked In", 1, (255, 255, 255))
            else:
                text2 = font.render("Waiting...", 1, (255, 255, 255))

        if p == 1:
            win.blit(text2, (180, 350))
            win.blit(text1, (440, 350))
        else:
            win.blit(text1, (180, 350))
            win.blit(text2, (440, 350))

        for btn in btns:
            btn.draw(win)

    pygame.display.update()


btns = [Button("Rock", 180, 500, (255,99,71)), Button("Scissors", 440, 500, (255,99,71)), Button("Paper", 680, 500, (255,99,71))]
def main():
    run = True
    clock = pygame.time.Clock()
    n = Network()
    player = int(n.getP())
    print("You are player", player)

    while run:
        clock.tick(60)
        try:
            game = n.send("get")
        except:
            run = False
            print("Couldn't get game")
            break

        if game.bothWent():
            redrawWindow(win, game, player)
            pygame.time.delay(500)
            try:
                game = n.send("reset")
            except:
                run = False
                print("Couldn't get game")
                break

            font = pygame.font.SysFont("lucid-bold", 90)
            if (game.winner() == 1 and player == 1) or (game.winner() == 0 and player == 0):
                text = font.render("You Won!", 1, (255,255,255))
            elif game.winner() == -1:
                text = font.render("Tie Game!", 1, (255,255,255))
            else:
                text = font.render("You Lost!", 1, (255, 255, 255))

            win.blit(text, (width/2 - text.get_width()/2, height/2 - text.get_height()/2))
            pygame.display.update()
            pygame.time.delay(2000)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
                pygame.quit()

            if event.type == pygame.MOUSEBUTTONDOWN:
                pos = pygame.mouse.get_pos()
                for btn in btns:
                    if btn.click(pos) and game.connected():
                        if player == 0:
                            if not game.p1Went:
                                n.send(btn.text)
                        else:
                            if not game.p2Went:
                                n.send(btn.text)

        redrawWindow(win, game, player)

def menu_screen():
    run = True
    clock = pygame.time.Clock() 

    while run:
        clock.tick(60) #means while loop runs 60 times per second
        win.fill((0,191,255)) #the color of the gui window.
        font = pygame.font.SysFont("lucid-bold", 80)
        text = font.render("Click to play1",1, (255,255,255))  
       
        win.blit(text, (300,350)) 
        pygame.display.update()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                run = False
            if event.type == pygame.MOUSEBUTTONDOWN:
                run = False

    main()

while True:
    menu_screen()


#server localhost to  ip addr in server part 
#client change the local host in network