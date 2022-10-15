import pick_random_pixels
import main_random_colours
import main_sorting_colours

pick_random_pixels.pick_random_pixels()
todo = input("""Would you like to have a randomised image, or sorted by colour?
r: randomised
s: sorted\n""")

if todo == "r":
    main_random_colours.main_random_colours()
elif todo == "s":
    main_sorting_colours.main_sorting_colours()
else:
    print("Did you enter a correct option?")
    exit()
