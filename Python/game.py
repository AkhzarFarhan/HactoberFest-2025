import random

def play_game():
    choices = ["snake", "water", "gun"]
    user_choice = input("Enter your choice (snake/water/gun): ").lower()
    computer_choice = random.choice(choices)

    print(f"Computer chose: {computer_choice}")

    if user_choice == computer_choice:
        print("It's a tie!")
    elif user_choice == "snake":
        if computer_choice == "water":
            print("You win! Snake drinks water.")
        else:
            print("You lose! Gun shoots snake.")
    elif user_choice == "water":
        if computer_choice == "gun":
            print("You win! Water rusts the gun.")
        else:
            print("You lose! Snake drinks water.")
    elif user_choice == "gun":
        if computer_choice == "snake":
            print("You win! Gun shoots snake.")
        else:
            print("You lose! Water rusts the gun.")
    else:
        print("Invalid input. Please choose snake, water, or gun.")

play_game()