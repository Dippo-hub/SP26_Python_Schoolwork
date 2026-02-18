
added=[]
removed=[]
unsure=[]
deck={}
decklist=[]

import re
import fileinput
##Need to update to work with file
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
  try:
    with open('decks.txt','a') as file:
      stop_count=0
      commander_=input("Which commander to edit? ")
      for card___ in file.read().split('\n'):
       for to_be in added:
        match_c=re.search(commander_, card___)
        match_stop=re.search("Commander:", card___)
        if match_c:
          if found==True:
            continue
          else:
           found=True
           print(f'Found {card___}')
        if found==True:
           if not match_stop:
            target_keyword = commander_  # The header you're looking for
            text_to_add = to_be 

# inplace=True redirects stdout to the file itself
            for line in fileinput.input('decks.txt', inplace=True):
             print(line, end="")  # Print original line back to file
            if target_keyword in line:
              print(text_to_add)
              continue
        elif stop_count==0:
         stop_count+=1
        else:
          break
            
           
    if found==False:
     print(f'Card {cut} not found.')
    
  except Exception as e:
      print(F"An error occured: {e}")

def getDeck():
  deck={} 
  action=input("Enter cards by (T)ext or by (F)ile? ").upper()
  if action=='T':
    cards=input("Enter deck as plain text: ").split('\n')
    ##Handling for text entry needed.
    print(deck)
  if action=='F':
    stuff=input("Enter decklist file name: ")
    try:
      with open(stuff, 'r') as file:
        cards_=file.read().split('\n')
        for card_ in cards_:
          match=re.search(r"(\d+)\s*(.*)", card_)
          if match:
           quantity = int(match.group(1))
           name = match.group(2)
           deck.update({name : quantity})
    except Exception as e:
      print(F"An error occured: {e}")
    try:
      with open('decks.txt', 'a') as file:
        cmdr=input("Enter commander: ")
        file.write(f"\n\nCommander: 1 {cmdr}\n\n")
        for name, qty in deck.items():
            if name!=cmdr:
             file.write(f"{qty} {name}\n")
    except FileNotFoundError:
     print("File not found.")
    viewDeck()
  else:
    print("Invalid input.")


def viewDeck():
  commander=input("Enter commander: ")
  found=False
  try:
    with open('decks.txt','r') as file:
      stop_count=0
      for card__ in file.read().split('\n'):
        match_c=re.search(commander, card__)
        match_stop=re.search("Commander:", card__)
        if match_c:
          if found==True:
            continue
          else:
           found=True
           print(f'Found {card__}')
        if found==True:
           if not match_stop:
            print(card__)
            continue
           elif stop_count==0:
             stop_count+=1
           else:
             break
            
           
    if found==False:
     print(f'Commander {commander} not found.')
    
  except Exception as e:
      print(F"An error occured: {e}")



while 1:
  action=int(input("1: Add decklist.\n2: Edit decklist.\n3: View Decklist.\n4: Quit. "))
  if (action==1):
    getDeck()
  if (action==2):
    editDeck
  if (action==3):
    viewDeck()
  if action==4:
    print("Quitting.")
    break
