import sys
import random

# Game data: (question, options, correct_option)
question_data = [
    ("What is the capital of France?",
     ["A. Berlin", "B. Madrid", "C. Paris", "D. Rome"], "C"),

    ("Which planet is known as the Red Planet?",
     ["A. Earth", "B. Mars", "C. Venus", "D. Jupiter"], "B"),

    ("Who wrote 'Hamlet'?",
     ["A. Charles Dickens", "B. Mark Twain", "C. William Shakespeare", "D. Jane Austen"], "C"),

    ("What is the chemical symbol for water?",
     ["A. H2O", "B. CO2", "C. NaCl", "D. O2"], "A"),

    ("Which language is used to create Android apps?",
     ["A. Swift", "B. Kotlin", "C. Ruby", "D. PHP"], "B"),

    ("What is the hardest natural substance on Earth?",
     ["A. Gold", "B. Iron", "C. Diamond", "D. Quartz"], "C"),

    ("Who painted the Mona Lisa?",
     ["A. Picasso", "B. Van Gogh", "C. Leonardo da Vinci", "D. Rembrandt"], "C"),

    ("What is the largest ocean on Earth?",
     ["A. Atlantic", "B. Indian", "C. Arctic", "D. Pacific"], "D"),

    ("In which year did World War II end?",
     ["A. 1940", "B. 1945", "C. 1939", "D. 1950"], "B"),

    ("Which gas do plants use for photosynthesis?",
     ["A. Oxygen", "B. Hydrogen", "C. Carbon Dioxide", "D. Nitrogen"], "C"),

    ("Who discovered gravity?",
     ["A. Newton", "B. Einstein", "C. Tesla", "D. Galileo"], "A"),

    ("What is the square root of 144?",
     ["A. 12", "B. 11", "C. 10", "D. 14"], "A"),

    ("What is the currency of Japan?",
     ["A. Yuan", "B. Yen", "C. Won", "D. Dollar"], "B"),

    ("Which continent is the Sahara Desert located in?",
     ["A. Asia", "B. North America", "C. Africa", "D. Europe"], "C"),

    ("Who developed the theory of relativity?",
     ["A. Isaac Newton", "B. Galileo Galilei", "C. Marie Curie", "D. Albert Einstein"], "D")
]

# Money levels
money_levels = [
    "$100", "$200", "$300", "$500", "$1,000",
    "$2,000", "$4,000", "$8,000", "$16,000", "$32,000",
    "$64,000", "$125,000", "$250,000", "$500,000", "$1,000,000"
]

def play_game():
    # Shuffle questions
    questions = question_data.copy()
    random.shuffle(questions)

    print("\n🎉 Welcome to 'Who Wants to Be a Millionaire!' 🎉")
    print("Answer each question by typing A, B, C, or D.\n")

    for i in range(len(questions)):
        q, options, correct = questions[i]
        print(f"\nQuestion {i+1} for {money_levels[i]}:")
        print(q)
        for option in options:
            print(option)

        while True:
            answer = input("Your answer (A/B/C/D): ").strip().upper()
            if answer in ['A', 'B', 'C', 'D']:
                break
            else:
                print("❌ Invalid input. Please enter A, B, C, or D only.")

        if answer == correct:
            print(f"✅ Correct! You've won {money_levels[i]}!")
        else:
            print(f"❌ Wrong answer. The correct answer was {correct}.")
            print(f"You leave with {'$0' if i == 0 else money_levels[i-1]}.\n")
            return  # Game ends

    print("\n🎊 Congratulations! You are now a MILLIONAIRE! 🏆💰")

def main():
    while True:
        play_game()
        while True:
            retry = input("\nWould you like to play again? (Y/N): ").strip().upper()
            if retry == "Y":
                break  # Start again
            elif retry == "N":
                print("👋 Thanks for playing! Goodbye.")
                sys.exit()
            else:
                print("Please enter Y or N.")

# Run the game
if __name__ == "__main__":
    main()
