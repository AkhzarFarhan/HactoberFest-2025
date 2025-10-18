import time

def countdown(seconds):
    while seconds:
        mins, secs = divmod(seconds, 60)
        timer = f"{mins:02d}:{secs:02d}"
        print(timer, end="\r")
        time.sleep(1)
        seconds -= 1
    print("⏰ Time’s up!")

if __name__ == "__main__":
    total_seconds = int(input("Enter countdown time in seconds: "))
    countdown(total_seconds)
