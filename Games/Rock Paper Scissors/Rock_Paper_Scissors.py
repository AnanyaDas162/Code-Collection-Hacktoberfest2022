import random

def Game(comp, you):
    if comp==you:
        return None

    elif comp=="Rock":
        if you=="Paper":
            return True
        elif you =="Scissors":
            return False   

    elif comp=="Paper":
        if you=="Rock":
            return False
        elif you =="Scissors":
            return True    

    elif comp=="Scissors":
        if you=="Paper":
            return False
        elif you =="Rock":
            return True    

print("Computer's Turn -> Rock / Paper / Scissors (computer has decided)\n")
# Random number generate between 1 and 3
n=random.randint(1,3)

if n==1:
    comp="Rock"
if n==2:
    comp="Paper"
if n==3:
    comp="Scissors"


you=input("Your Turn -> 'r' for Rock / 'p' for Paper / 's' for Scissors : \n")
if you=="r":
    you="Rock"
elif you=="p":
    you="Paper"
elif you=="s":
    you="Scissors"

print("Computer's choice is : ", comp)
print("Your choice is : ", you)

result=Game(comp, you)
if result==None:
    print("Ohh, It's a tie game")
elif result:
    print("Hurrah! You win the game")
else:
    print("Sorry! You lose the game")
