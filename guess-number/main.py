# Include an ASCII art logo.
from art import logo
import random


print(logo)
print("""Welcome to the Number Guessing Game!
I'm thinking of a number between 1 and 100.""")
#generate random number
answer=random.randint(1,100)

# Include two different difficulty levels (e.g., 10 guesses in easy mode, only 5 guesses in hard mode).
level=input("Choose a difficulty. Type 'easy' or 'hard': ")
guess=0
user_input=0
if level=='easy':
    guess=10
else:
    guess=5
# Allow the player to submit a guess for a number between 1 and 100.
while user_input!=answer and guess:
    # Check user's guess against actual answer. Print "Too high." or "Too low." depending on the user's answer.
    print(f"You have {guess} attempts remaining to guess the number.")
    user_input=int(input("Make a guess: "))
    if user_input==answer:
        print("Bravo!!!! you guessed it.")
        # If they got the answer correct, show the actual answer to the player.
        print(f"The correct answer is: {answer}")
    # Track the number of turns remaining.
    elif user_input>answer:
        print("too high")
    else:
        print("too low")
    guess-=1;
    # If they run out of turns, provide feedback to the player.
    if guess==0:
        print("you are out of turns.")
        print(f"The correct answer was {answer}")
