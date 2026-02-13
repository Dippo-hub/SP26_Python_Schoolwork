
added=[]
removed=[]
unsure=[]

decklist=[]
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
    for item in deck:
      if item==card:
        deck[item]+=1
      else:
        deck.update(card, 1)
  print(deck)

def getDeck():
  action=input("Enter cards by (T)ext or by (F)ile? ").upper()
  if action=='T':
    cards=input("Enter deck as plain text: ").split('\n')
    for card in cards:
      for item in deck:
        if item==card:
          deck[item]+=1
        else:
          deck.update(card, 1)
    print(deck)
  if action=='F':
    stuff=input("Enter decklist file name: ")
    try:
      with open(stuff, 'r') as file:
        cards=file.read().split('\n')
        for card in cards:
          match=re.search(r"(\d+),\s*(.*)", card)
          if match:
           quantity = int(match.group(1))
           name = match.group(2)
           deck.update({name : quantity})
    except Exception as e:
      print(F"An error occured: {e}")
    print(deck)
  else:
    print("Invalid input.")


def viewDeck():
  for card in deck:
    print(f"{card} {deck[card]}")


while 1:
  action=int(input("1: Add decklist.\n2: Edit decklist.\n3: View Decklist.\n4: Quit. "))
  if (action==1):
    getDeck()
  if (action==2):
    editDeck
  if (action==3):
    viewDeck()
  if action==4:
    break
