def lets_play_again():
    
    print("\n Do you want yo play again? (y/n)")
    answer=input(">").lower()
    if (answer=="y"):
        start()
    else :
        exit()
        
def game_over():
    print("\n Game over")


def treasure_room():
    print("You made the right call.")
    print("\nYou are now in a room filled with diamonds !")
    print ("And there is a door too!")
    print("What would you do? (1 or 2)")
    print("1). Take some diamonds and go through the door.")
    print("2). Just go through the door.")
    choicex=input()
    if (choicex=="1"):
        print("Uh oh!You messed up in the end")
        game_over()
        lets_play_again()
        
    elif (choicex=="2"):
        print("Kudos! You Win")
        lets_play_again()
        
    


def monster_room():
    print("You decided to enter through the right door")
    print ("Now you have entered the room of a monster!")
    print("The monster is sleeping.\nBehind the monster, there is another door.What would you do? (1 or 2)")
    print("1). Go through the door silently.")
    print("2). Kill the monster and show your courage!")
    choicey=input()
    if (choicey=="1"):
        treasure_room()
        
    if (choicey=="2"):
        print("The monster was hungry, it ate you")
        game_over()
        lets_play_again()


def snake_room():
    print("You decided to enter through the left door")
    print("There is a snake here.")
    print("Behind the Snake is another door.")
    print("The snake is having eggs!")
    print("What would you do? (1 or 2)")
    print("1). Take the eggs.")
    print("2). Taunt the snake.")
    choicez=input()
    if (choicez=="1"):
        print("You want the eggs not the treasure !!That's why the snake killed you")
        game_over()
        lets_play_again()
    if (choicez=="2"):
        treasure_room()


def start():
    print("You are standing in a dark room.")
    print("\nThere is a door to your left and right, which one do you take? (l or r)")
    choice=input().lower()
    if (choice=="l"):
        snake_room()
    elif (choice=="r"):
        monster_room()
    else :
        game_over()
        lets_play_again()

start()

