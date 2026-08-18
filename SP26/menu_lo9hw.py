

class Menu:
    
    def __init__(self):
        self._options = []

    def addOption(self, option):
        self._options.append(option)

    def _display(self):
        #Display the menu options.
        for i, option in enumerate(self._options, 1):
            print(f"{i} {option}")

    def getInput(self):
        #Displays the menu
        while True:
            self._display()
            user_input = input("Enter choice: ")
            
            # Validation
            if user_input.isdigit():
                choice = int(user_input)
                if 1 <= choice <= len(self._options):
                    return choice
            
            print(f"Invalid input. Please enter a number between 1 and {len(self._options)}.")


