import time as t
import random as r
#Using the time library


name = input('Enter Your Name here : ')
print('Hello, ' + name, 'Time to play Hangman')
t.sleep(1) #suspends the execution for a couple of seconds; here for 1s
print('Start guessing .. \n')
t.sleep(0.5)
Enter Your Name here : Karma Akabane
Hello, Karma Akabane Time to play Hangman
Start guessing .. 

#Appending the secret words

#List of secret words 
words = ['Hinata', 'Sakura', 'Kakashi', 'Sasuke', 'Naruto', 'Anime']
word = r.choice(words)
guesses = ''
turns = 5
Logic

while turns > 0:
  failed = 0 
  for char in word:
    if char in guesses:
      print(char, end = '')
    else:
      print('_', end = '')
      failed += 1
  if failed == 0:
    print('\n You Win')
    break
  guess = input('\n Guess a character: ')
  guesses += guess
  if guess not in word:
    turns -= 1
    print("\n Wrong! Try Again")
    print('\n You have ', + turns, 'more guesses')
    if turns == 0:
      print('\n You Lose')
