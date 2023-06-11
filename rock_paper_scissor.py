import random

#write the main code
rock = '''
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)T
'''

paper = '''
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''

scissor = '''
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''

#Write your code below this line 👇

print("What do you choose? Type 0 for rock, 1 for paper, or 2 for scissor.")

#get user input

user_input=int(input())

#code for computer input
computer_input=random.randint(0,2)

#user inut when it is 0: rock;
if user_input==0:
    #compute input when it is 0
    if computer_input==0:
        print("user input: rock")
        print(rock+"\n\n\n")
        print("Computer input: rock")
        print(rock+"\n\n\n")
        print("\n\nGame Draw!!!\n\n")

    #compute input when it is 1
    elif computer_input==1:
        print("user input: rock")
        print(rock+"\n\n\n")
        print("Computer input: paper")
        print(paper+"\n\n\n")
        print("\n\nYou Lost\n\n")

    #compute input when it is 2
    elif computer_input==2:
        print("user input: rock")
        print(rock+"\n\n\n")
        print("Computer input: scissor")
        print(scissor+"\n\n\n")
        print("\n\nYou Won!!!!\n\n")


#user input for 1: paper
elif user_input==1:

    #compute input when it is 0
    if computer_input==0:
        print("user input: paper")
        print(paper+"\n\n\n")
        print("Computer input: rock")
        print(scissor+"\n\n\n")
        print("\n\nYou Won!!!!\n\n")

    #compute input when it is 1
    elif computer_input==1:
        print("user input: paper")
        print(paper+"\n\n\n")
        print("Computer input: paper")
        print(scissor+"\n\n\n")
        print("\n\nGame Draw!!!\n\n")

    #compute input when it is 2
    else:
        print("user input: paper")
        print(paper+"\n\n\n")
        print("Computer input: scissor")
        print(scissor+"\n\n\n")
        print("\n\nYou Lost\n\n")


#user input for 2: scissor
else:
    #compute input when it is 0
    if computer_input==0:
        print("user input: scissor")
        print(scissor+"\n\n\n")
        print("Computer input: Rock")
        print(scissor+"\n\n\n")
        print("\n\nYou Lost\n\n")

    #compute input when it is 1
    elif computer_input==1:
        print("user input: scissor")
        print(scissor+"\n\n\n")
        print("Computer input: paper")
        print(scissor+"\n\n\n")
        print("\n\nYou Won!!!!\n\n")

    #compute input when it is 2
    elif computer_input==2:
        print("user input: scissor")
        print(scissor+"\n\n\n")
        print("Computer input: scissor")
        print(scissor+"\n\n\n")
        print("\n\nGame Draw!!!\n\n")

