"""Middle-Earth is at war! Loyal races to Sauron will fight against 
other benevolent races that do not want evil to reign over their lands.
Each race has an associated "value" between 1 and 5:
 - Benevolent Races: Pelosos (1), Good Southerners (2), Dwarves (3), 
   Númenóreans (4), Elves (5)
 - Evil Races: Evil Southerners (2), Orcs (2), Goblins (2), 
   Wargs (3), Trolls (5)
Create a program that calculates the result of the battle between
the 2 types of armies:
 - The result can be a victory for good, evil, or a draw, depending 
   on the sum of the army's value and the number of members.
 - Each army can be composed of a variable number of members 
   from each race.
 - You have total freedom to model the data for the exercise.
Example: 1 Peloso loses to 1 Orc
         2 Pelosos draw against 1 Orc
         3 Pelosos defeat 1 Orc
"""
from random import randint
from os import system, name

def clearScreen():
  # Clear console
    system('cls' if name == 'nt' else 'clear')

def numberVerify(num, optionalNumber):
  # Verify if the entered string is numeric
    if num.isnumeric():
        return num
    else:
        print("You can't enter a non-numeric character")
        chooseAlliesTroop(optionalNumber)

def nameVerify(name):
  # Verify if the entered string is alphanumeric
  if name.isalnum():
    return name
  else:
    clearScreen()
    print('You didn\'t enter a correct name')
    menuPreview()

def constuctTroops(name):
  # Build the allied troops within a random range
  numOfAlliesTroops = randint(len(name) - 3, (len(name) * 5) + 3)
  alliesTroops = chooseAlliesTroop(numOfAlliesTroops)
  return alliesTroops
 
def knowEnemiesTroops(name, variableControl=True):
  # Build and display enemy troops in the console
  enemiesTroops = createEnemiesTroops(name)
  system('cls')
  # Verify whether or not to display the enemies (variableControl)
  if variableControl:
    print("The enemies are:")
    for i in enemiesTroops:
      for enemies, valuesOfEnemies in i.items():
        print(f"name: {enemies} value: {valuesOfEnemies}")
  return enemiesTroops
  
def chooseAlliesTroop(yourCredits):
  allies = [
      {'Pelosos': 1},
      {'Good Southerners': 2},
      {'Dwarves': 3},
      {'Númenóreans': 4},
      {'Elves': 5}
  ]
  alliesTroops = []
  print(f"Now you are going to choose your allied troops")

  # Generate question/response for the user to select from the available options (allied troops)
  while yourCredits > 0:
    # Display available allied troops
    print(f"You have {yourCredits} available slots, the allied troops are:")
    for i, ally in enumerate(allies, start=1):
        for troop, value in ally.items():
            print(f"{i} --> name: {troop} value: {value}")
    try:
      choose = int(input("Which ally would you like to take to battle? (1-5): "))

      # Add in dictionary format within a list to maintain an order list[dictionary{alliesName: power}]
      if 1 <= choose <= len(allies) and yourCredits >= allies[choose - 1][list(allies[choose - 1].keys())[0]]:
        alliesTroops.append(allies[choose - 1])
        yourCredits -= allies[choose - 1][list(allies[choose - 1].keys())[0]]
        clearScreen()
      else:
        clearScreen()
        print("You do not have enough credits or your selection is not valid.")
    except ValueError:
      clearScreen()
      print("Please enter a valid number.")   
  return alliesTroops

def createEnemiesTroops(name):
  enemies = [
    {'Evil Southerner': 2},
    {'Orc': 2},
    {'Goblin': 2},
    {'Warg': 3},
    {'Troll': 5}
  ]
  troopsEnemies = []
  # Randomly generate the number of enemy troops (numOfEnemiesTroops) and add list-[dictionary{enemiesTroops: power}]
  numOfEnemiesTroops = randint((len(name) * 5) - 5, len(name) * 5)
  while numOfEnemiesTroops > 0:
    numRandom = randint(1, 4)
    if numRandom > numOfEnemiesTroops:
      # Choose enemy to introduce by position in the enemies list
      troopsEnemies.append(enemies[numOfEnemiesTroops])
      numOfEnemiesTroops = 0
    elif numRandom <= numOfEnemiesTroops:
      troopsEnemies.append(enemies[numRandom])
      numOfEnemiesTroops -= numRandom
  return troopsEnemies

def createEnemiesTroops(name):
    enemies = [
        {'Evil Southerner': 2},
        {'Orc': 2},
        {'Goblin': 2},
        {'Warg': 3},
        {'Troll': 5}
    ]
    troopsEnemies = []
    # Randomly generate the number of enemy troops (numOfEnemiesTroops) and add list-[dictionary{enemiesTroops:power}]
    numOfEnemiesTroops = randint((len(name) * 5) - 5, len(name) * 5)
    while numOfEnemiesTroops > 0:
        numRandom = randint(1, 4)
        if numRandom > numOfEnemiesTroops:
            # Choose an enemy to add by position in the enemies list
            troopsEnemies.append(enemies[numOfEnemiesTroops])
            numOfEnemiesTroops = 0
        elif numRandom <= numOfEnemiesTroops:
            troopsEnemies.append(enemies[numRandom])
            numOfEnemiesTroops -= numRandom
    return troopsEnemies


def war(alliesTroops, enemiesTroops):
    print("The battle has begun!")
    round_number = 1

    while alliesTroops and enemiesTroops:

        print(f"\n--- Round {round_number} ---")
        enemy = enemiesTroops.pop(0)  # Take the first enemy from the list
        enemy_name, enemy_power = list(enemy.items())[0]
        print(f"Oh no! A {enemy_name} with a power of {enemy_power} is approaching.")

        # Display available allied troops
        print("Your available troops are:")
        for i, ally in enumerate(alliesTroops, start=1):
            ally_name, ally_power = list(ally.items())[0]
            print(f"{i} -> {ally_name} (Power: {ally_power})")
        
        try:
            # Ask the player to choose an allied troop
            choice = int(input("Select the number of the allied troop to fight: "))
            if 1 <= choice <= len(alliesTroops):
                selected_ally = alliesTroops.pop(choice - 1)
                ally_name, ally_power = list(selected_ally.items())[0]
                clearScreen()
                print(f"You selected {ally_name} (Power: {ally_power}) to face {enemy_name} (Power: {enemy_power}).")

                # Combat resolution
                if ally_power < enemy_power:
                    print(f"{ally_name} has less power than {enemy_name}. Reducing the enemy's power!")
                    enemy_power -= ally_power  # Reduce the enemy's power
                    if enemy_power > 0:
                        print(f"{enemy_name} survives with a power of {enemy_power}.")
                        enemiesTroops.append({enemy_name: enemy_power})  # The enemy returns with reduced power
                    else:
                        print(f"{enemy_name} has been defeated.")
                elif ally_power == enemy_power:
                    print(f"{ally_name} has equal power to {enemy_name}. Both fall in battle!")
                else:
                    print(f"{ally_name} has more power than {enemy_name}. Reducing the ally's power!")
                    ally_power -= enemy_power  # Reduce the ally's power
                    if ally_power > 0:
                        print(f"{ally_name} survives with a power of {ally_power}.")
                        alliesTroops.append({ally_name: ally_power})  # The ally returns with reduced power
                    else:
                        print(f"{ally_name} has been defeated.")
            else:
                print("Invalid selection. You lose this chance.")
            print("""

                    -----------------------------------------------------------------------------

            """)
        except ValueError:
            print("Please enter a valid number.")

        round_number += 1

    # Determine the final result
    if alliesTroops:
        print("\nCongratulations! The allied troops have won the battle.")
        exit()
    else:
        print("\nOh no! The enemy troops have won the battle.")
        exit()

def menuPreview():
    # Welcome menu
    print("""Welcome to Medieval History. We need your help!!. 
    """)
    menu(nameVerify(input('What is your name: ')))

def menu(name, controlVariable=True):
    # Get the player's name and use controlVariable to determine whether to display it
    if controlVariable:
        print(f"""
      Hello {name}, thank you for helping us.
      Our village is being attacked by an army of evil troops.
          You will have to build an army to fight these troops and defend our village.
          Press:
          1 - See how many enemy troops are coming.
          2 - Build your troops.
          3 - Exit
      """)
    else:
        print(f"""
      {name}, it's time to build our army to be ready and defend against the enemies
      Press:
        1 - See how many enemy troops are coming.
        2 - Build your troops.
        3 - Exit
    """)
    # Option for the player to choose
    option = input('Choose an option:')
    menuOptions(option, name)

def menuOptions(option, name):
    # Identify the option chosen by the user
    enemiesTroops = []
    if option == '1':
        enemiesTroops = knowEnemiesTroops(name)
        menu(name, False)
    elif option == '2':
        if len(enemiesTroops) == 0:
            enemiesTroops = knowEnemiesTroops(name, False)
        alliesTroops = constuctTroops(name)
        war(alliesTroops, enemiesTroops)
    elif option == '3':
        exit()
    else:
        print('Your choice isn\'t in the available options')
        menu(name)

# Program initializer
def __init__():
    menuPreview()

__init__()
