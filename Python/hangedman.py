import random

images = ['''

    +---+
    |   |
        |
        |
        |
        |
        =========''', '''

    +---+
    |   |
    O   |
        |
        |
        |
        =========''', '''

    +---+
    |   |
    O   |
    |   |
        |
        |
        =========''', '''

    +---+
    |   |
    O   |
   /|   |
        |
        |
        =========''', '''

    +---+
    |   |
    O   |
   /|\  |
        |
        |
        =========''', '''

    +---+
    |   |
    O   |
   /|\  |
    |   |
        |
        =========''', '''

    +---+
    |   |
    O   |
   /|\  |
    |   |
   /    |
        =========''', '''

    +---+
    |   |
    O   |
   /|\  |
    |   |
   / \  |
        =========''']

words = [
'diane','ubuntu','master','race','razer','games','leon','flowers','fuck'
]
letter_used = []

def random_word():
    idx = random.randint(0,len(words)-1)
    return words[idx]

def display_board(hidden_word,tries,):
    print(images[tries])
    print('')
    print(hidden_word)
    print('')
    print('Letters used')
    print(letter_used)
    print('---- * ---- * ---- * ---- * ---- * ----')

    
def run():
    word = random_word()
    hidden_word = ['-'] * len(word)
    tries = 0

    while True:
        display_board(hidden_word,tries)
        current_letter = str(input('Try a letter: '))
        letter_used.append(current_letter)


        letter_indexes = [
            idx for idx in range(len(word)) if word[idx] == current_letter
        ]

        if not letter_indexes:
            tries +=1

            if tries == 7:
                display_board(hidden_word,tries)
                print('')
                print('Sorry, you lose :c')
                print('The word was {}'.format(word))
                break
        else:

            for idx in letter_indexes:
                hidden_word[idx] = current_letter

            letter_indexes = []

        try:
             hidden_word.index('-')
        except ValueError:
            print('')
            print('Congrats, you won, the word was {}'.format(word))
            break
    

if __name__ == '__main__':
    print('Welcome to leon hanged man')
    run()
