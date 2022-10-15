import random
def pick_random_pixels():
  # reset file to make sure that all works smoothly
  f = open("me.txt", 'w')
  f.write("")
  f.close()

  f = open("me.txt", 'a')
  w = str(input("Enter the width of the image you want (in px):\n"))
  h = str(input("Enter the height of the image you want (in px):\n"))
  f.write("w" + w + "\n")
  f.write("h" + h + "\n")
  for i in range(int(w) * int(h)):
    var = random.randint(1, 262144)
    f.write(str(var) + '\n')

  f.close()
    
