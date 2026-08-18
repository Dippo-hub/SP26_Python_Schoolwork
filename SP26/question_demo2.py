##
#  a simple quiz with two choice questions.
#

#from questions import ChoiceQuestion
from SP26.questions import *

def main() :
   first = ChoiceQuestion()
   first.setText("In what year was the Python language first released?")
   first.addChoice("1991", True)
   first.addChoice("1995", False)
   first.addChoice("1998", False)
   first.addChoice("2000", False)

   second = ChoiceQuestion()
   second.setText("In which country was the inventor of Python born?")
   second.addChoice("Australia", False)
   second.addChoice("Canada", False)
   second.addChoice("Netherlands", True)
   second.addChoice("United States", False)

   third= Question()
   third.setText("Who was the inventor of Python?")
   third.setAnswer("Guido van Rossum")


   presentQuestion(first)
   presentQuestion(second)
   presentQuestion(third)

## Presents a question to the user and checks the response.
#  @param q the question
#
def presentQuestion(q) :
   print(q)
   response = input("Your answer: ")
   print(q.checkAnswer(response))

# Start the program.
main()
