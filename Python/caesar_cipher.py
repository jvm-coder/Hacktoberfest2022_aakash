def encrypt(string, shift):
  r = ''
  for c in string:
    if c == ' ':
      r = r + c
    elif  c.isupper():
      r = r + chr((ord(c) + shift - 65) % 26 + 65)
    else:
      r = r + chr((ord(c) + shift - 97) % 26 + 97)
  
  return r

text = input("Enter a string to encrypt: ")
shift= int(input("Enter a key(shift): "))

print("Entered text: ", text)
print("Key(Shift): ", shift)
print("Encrypted Text: ", encrypt(text, shift))