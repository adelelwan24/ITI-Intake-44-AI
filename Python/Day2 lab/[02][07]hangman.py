import random
pool = ['adel', 'work', 'play', 'anime']

userName = input("Please enter your name: ")


word = random.choice(pool)
maxGuess = 7
guessList = ["_"] * len(word)
print(guessList)
for i in range(maxGuess):
    guess = input("Guess any alphabet: ")
    if len(guess) == 1 and guess in word:
        index = word.index(guess)

        guessList[index] = guess
        print("".join(guessList))
    if "".join(guessList) == word:
        print("Congratulation! you got it right!!")
        break
    