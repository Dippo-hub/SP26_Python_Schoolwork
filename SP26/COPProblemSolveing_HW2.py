##
#  Manage student grades.
#

# Use a dictionary named 'grades' to track student grades.
grades={}
action=""

  # Loop until the user chooses to quit.
  # Check user input for the following "(A)dd, (R)emove, (M)odify, (P)rint all, or (Q)uit? "
  # Prevent unexected inputs by converting input to upper-case
while (action!='Q'):
    action=input("(A)dd, (R)emove, (M)odify, (P)rint all, or (Q)uit? ")
    action=str.upper(action)
    

   # Use a condition to handle adding a new student.
   # Convert grade into integer
   # Gather user input for "Enter the name of the student: "
   # Check if student name already exists "Sorry, that student is already present."
   # Gather user input for student grade "Enter the student's grade: "
   # Validate input is in correct format or range, if not notify "Please enter grade as number 0-100"
    if (action=="A"):
        name=input("Enter the student's name: ")
        for student in grades:
            if (student==name):
                print("Sorry, that student is already present.")
                break
        grade=int(input(f"Enter {name}'s grade: "))
        if (grade.is_integer):
            grades[name]=grade
        else:
            print("Please enter grade as a number.")
        
 

   # Handle removing a student if user inputs 'R'
   # Check input for "What student do you want to remove? "
   # use pop to remove key/value form grades
   # see notes https://www.programiz.com/python-programming/methods/dictionary/pop
   # Check if student doesn't exist - "Sorry, that student doesn't exist and couldn't be removed."
    elif (action=="R"):
     remove=input("Which student do you want to remove? ")
     present=0
     for student in grades:
        if (student==remove):
            present=present+1
     if (present==0):
        print(f"{remove} does not exist.")
     else:
        grades.pop(remove)
     
 

   # Handle modifying a student grade if user inputs 'M'
   # "Enter the name of the student to modify: "
   # Convert grade into integer
   # If student is in grades dictionary, show existing grade "The old grade is"
   # Gather input for new grade "Enter the new grade: "
   # If student doesn't exist "Sorry, that student doesn't exist and couldn't be modified."
    elif(action=="M"):
     modify=input("Enter the name of the student to modify: ")
     present=0
     for student in grades:
        if (student==modify):
            present=present+1
     if (present==0):
        print(f"{modify} does not exist.")
     else:
        print(f"The old grade is {grades[modify]}")
        change=int(input("Enter new grade: "))
        grades[modify]=change
 
   # Handle printing grade average as a string if user input is 'P'
   # Use "The average grade is "
   # Handle printing all of the student names with associated grade
   # Display explictly as strings
    elif (action=="P"):
       average=0
       number=0
       for student in grades:
          print(f"{student} has a score of {grades[student]}")
          average=average+grades[student]
          number+=1
       average=average/number
       print(f"The average grade is {average}")
       


 
      

   # Handle the case for quiting if user inputs 'Q' "Goodbye!"
    elif (action=="Q"):
       print("Goodbye!")
       break
 

   # Handle the case of invalid input. "Sorry, that wasn't a valid choice."
    else:
       print("Sorry, that was an invalid input.")
 