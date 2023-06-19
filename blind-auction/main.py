#import ascii art
from art import logo

#start the code
print(logo)
list={}
others='y'
while others=='y':
    print("Welcome to the secret auction program.")
    name=input("What is your name? ")
    bid=input("What is your bid? $")
    list[name]=bid
    others=input("Are there any other bidders? (y/n) ")

print(list)
max_bid=0 
winner=""
for data in list:
    if int(list[data])>int(max_bid):
        max_bid=list[data]
        winner=data
print(f"The winner is {winner} with a bid of ${max_bid}")
