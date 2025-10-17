def count_words(text):
    words = text.split()  
    return len(words)  


text = "Hello, welcome to the world of Python!"
word_count = count_words(text)
print(f"Number of words: {word_count}")
