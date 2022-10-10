from PIL import Image

def hex_to_rgb(value):
    """Return (red, green, blue) for the color given as #rrggbb."""
    value = value.lstrip('#')
    lv = len(value)
    return tuple(int(value[i:i + lv // 3], 16) for i in range(0, lv, lv // 3))

def main_sorting_colours():
  tempFile = open("me.txt","r")
  contents = tempFile.read().splitlines()
  tempFile.close()

  coloursTemp = open("colours_new.txt", "r")
  colours = coloursTemp.read().splitlines()
  coloursTemp.close()

  length = len(contents)
  startLine = 0
  imageOp = "na"
  hex_codes = []
  #open colours.txt
  #get specific line corresponding to number
  #get first 7 chars

  for number in range(length):
    if 'w' in contents[startLine-1]:
      width = contents[startLine-1][1:]
      startLine = startLine + 1
    elif 'h' in contents[startLine-1]:
      height = contents[startLine-1][1:]
      startLine = startLine + 1
    
    else :
      index = int(contents[startLine-1])
      line = colours[index-1]
      hexCode = line[0:7]
      hex_codes.append(hexCode)
      startLine =startLine + 1

  hex_codes.sort()
  hex_codes.reverse()
  img = Image.new('RGB', (int(width), int(height)))
  wi = 0
  hi = 0
  for pix in hex_codes:
    img.putpixel((wi,hi), hex_to_rgb(pix))
    if wi == int(width) - 1:
      wi = 0
      hi += 1
    else:
      wi += 1
    
  img.save('output.png')

  wallpaper = img
  wallpaper.show()
