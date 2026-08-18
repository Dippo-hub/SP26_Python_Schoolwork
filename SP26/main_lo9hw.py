from SP26.menu_lo9hw import Menu
import os, subprocess

def run_bash_cmd(choice):
    # Mapping choice to actual Linux commands
    commands = {
        1: "free -h",
        2: "ip addr",
        3: "vmstat -s"
    }
    cmd = commands.get(choice)
    if cmd:
        result = subprocess.run(cmd, shell=True, capture_output=True, text=True)
        print(result.stdout)

def main():
    mainMenu=Menu()
    mainMenu.addOption("Check available memory")
    mainMenu.addOption("View network connections")
    mainMenu.addOption("Display free ram and swap")
    mainMenu.addOption("Quit")
    while True:
     action=mainMenu.getInput()
     print(f"You selected: {action}")
     #Handle "Quit" 
     if action == 4:
        print("Exiting...")
        break
            
        #Execute Linux utilities for other valid entries
     run_bash_cmd(action)

if __name__ == "__main__":
    main()
