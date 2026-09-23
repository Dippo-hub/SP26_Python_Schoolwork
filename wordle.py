import random

solutions = [
    "apple",
    "grape",
    "peach",
    "berry",]

class Wordle:
    def __init__(self):
        self.solution = random.choice(solutions)
        self.guesses = {}

    def guess(self, word):
        if len(word) != 5:
            return "Invalid guess. Please enter a 5-letter word."
        feedback = []
        for i in range(5):
            if word[i] == self.solution[i]:
                feedback.append("2")  # Correct letter and position
            elif word[i] in self.solution:
                feedback.append("1")  # Correct letter but wrong position
            else:
                feedback.append("0")  # Incorrect letter
        self.guesses[word] = ''.join(feedback)
        return ''.join(feedback)


    def play(self):
        print("Welcome to Wordle!")
        while True:
            guess = input("Enter your 5-letter guess (or 'exit' to quit): ")
            if guess.lower() == 'exit':
                print(f"The solution was: {self.solution}")
                break
            feedback = self.guess(guess)
            print(f"Feedback: {feedback}")
            if feedback == "22222":
                print("Congratulations! You've guessed the word correctly!")
                break

if __name__ == "__main__":
    game = Wordle()
    game.play()