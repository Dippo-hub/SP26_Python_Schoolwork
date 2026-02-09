
added=[]
removed=[]
unsure=[]

decklist=''
deck={}
import re

def editDeck():
  decklist=input("Enter decklist file: ")
  try:
    with open(decklist, 'r') as file:
     decklist=file.read().splitlines()
     for line in decklist:
       line=line.strip()
       if re.search("Added", line, re.IGNORECASE):
         card=re.sub(r"Added", "", line, re.IGNORECASE).strip()
         added.append(card)
       elif re.search("Removed",line, re.IGNORECASE):
         card=re.sub(r"Removed", "", line, re.IGNORECASE).strip()
         removed.append(card)
       else:
         unsure.append(line)
    print(f"Unsure: {unsure}\n")
    print(f"Added: {added}\n")
    print(f"Removed: {removed}\n")
    
  except Exception as e:
     print(f"An error occurred: {e}")
  for card in added:
    if 

#def getDeck():

def viewDeck():
  for card in deck:
    print(f"{card} {deck[card]}")


while 1:
  action=int(input("1: Add decklist.\n2: Edit decklist.\n3: View Decklist. "))
  #if (action==1):
    #getDeck()
  if (action==2):
    editDeck
  if (action==3):
    viewDeck()
