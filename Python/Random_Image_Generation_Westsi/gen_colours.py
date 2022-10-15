def rgb_to_hex(red, green, blue):
    """Return color as #rrggbb for the given color values."""
    return '#%02x%02x%02x' % (red, green, blue)

  
f = open('colours_new.txt', 'a')
for red in range(1,255,4):
  for green in range(1,255,4):
    for blue in range(1,255,4):
      f.write(str(rgb_to_hex(red, green, blue)) + "\n")

f.close()
