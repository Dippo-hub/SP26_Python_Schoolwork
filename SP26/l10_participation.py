# not_priv_fruit.py
class Fruit:
    def __init__(self, factor):
        self._factor = factor
    def op1(self):
        print('Op1 with factor {}...'.format(self._factor))
class Apple(Fruit): # subclass
    def op2(self, factor):
        self.__factor = factor
        print('Op2 with factor {}...'.format(self.__factor))
#obj = Apple('red')
#obj.op1()    # Op1 with factor red...
#obj.op2('green')  # Op2 with factor green...
#obj.op1()    # This should be red, but isn't
#print(obj.__dict__.keys())

class Form_X:
    def __init__(self, f_name):
        self._f_name = f_name

    @property
    def f_name(self):
        return self._f_name

    @f_name.setter
    def f_name(self, new_f_name):
        if not isinstance(new_f_name, str):
            raise ValueError("first name must be a string.")

        self._f_name = new_f_name

#Form_X = Form_X("Sabine")

#print(Form_X.f_name)   

#Form_X.f_name = 2187

#print(Form_X.f_name)   

class Menu:
    ## Constructs a menu with no options.
    #
    def __init__(self):
        self._options = []

    ## Adds an option to the end of menu.
    #  @param option the option to add
    #
    def addOption(self, option):
        self._options.append(option)

    ## Displays the menu, with options numbered starting with 1, and prompts
    #  the user for input. Repeats until a valid input is supplied.
    #  @return the number that the user supplied
    #
    def getInput(self):
        done = False
        while not done:
            print('-' * 80, '\n')
            for i in range(len(self._options)):
                print("%d %s" % (i + 1, self._options[i]))

            userChoice = int(input())
            if userChoice >= 1 and userChoice <= len(self._options):
                print(self._options[userChoice-1])
                continue
            if userChoice < 1 or userChoice > len(self._options)+1:
                print(f'Enter a 1-{len(self._options)+1} only')
                continue
            if userChoice==len(self._options):
                return "Goodbye"
                
                    
            else:
                done = True
                quit()

        return userChoice

def main():
    mainMenu = Menu()

    def buildOptions():
        action=input("Add option: ")
        mainMenu.addOption(action)

    buildOptions()
    buildOptions()
    buildOptions()
    choice = mainMenu.getInput()
    print(choice)

if __name__ == '__main__':
    main()
