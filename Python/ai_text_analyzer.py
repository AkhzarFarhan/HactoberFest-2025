from textblob import TextBlob

def analyze_text(text):
    blob = TextBlob(text)

    # Sentiment polarity: -1 (negative) to +1 (positive)
    sentiment_score = blob.sentiment.polarity

    # Determine sentiment label
    if sentiment_score > 0.2:
        sentiment = "😊 Positive"
    elif sentiment_score < -0.2:
        sentiment = "😞 Negative"
    else:
        sentiment = "😐 Neutral"

    # Basic emotion word detection
    emotions = []
    positive_words = ["love", "happy", "great", "amazing", "good", "awesome"]
    negative_words = ["hate", "bad", "terrible", "sad", "angry", "awful"]

    for word in blob.words:
        lw = word.lower()
        if lw in positive_words:
            emotions.append(f"Positive word: {lw}")
        elif lw in negative_words:
            emotions.append(f"Negative word: {lw}")

    # Output results
    print("\n=== AI TEXT ANALYZER ===")
    print(f"Text: {text}")
    print(f"Sentiment: {sentiment} (score={sentiment_score:.2f})")
    if emotions:
        print("Emotion cues:")
        for e in emotions:
            print("  •", e)
    else:
        print("No strong emotional words detected.")
    print("=========================\n")

def main():
    print("🧠 Welcome to the AI Text Analyzer!")
    print("Type your text (or 'exit' to quit).")

    while True:
        text = input("\nEnter text: ").strip()
        if text.lower() == 'exit':
            print("Goodbye!")
            break
        elif text:
            analyze_text(text)
        else:
            print("Please enter some text!")

if __name__ == "__main__":
    main()
