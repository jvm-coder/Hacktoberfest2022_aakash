import random
rand_number = random.randint(1,20)
#print(the secret number is , rand_number)
list_of_guesses = []
guess = int(input('Enter a number '))
list_of_guesses.append(guess)
while guess != rand_number
  if (guess  rand_number)
    print(The guess is too high!)
    guess = int(input('Enter another number '))
    list_of_guesses.append(guess)
  if (guess  rand_number)
    print(The guess is too low!)
    guess = int(input('Enter another number '))
    list_of_guesses.append(guess)
print(You got it!)
print(You guessed the following numbers , list_of_guesses)