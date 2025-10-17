import emoji

emoji_dict = {
    "love": emoji.emojize(":red_heart:"), 
    "pizza": emoji.emojize(":pizza:"),
    "sad": emoji.emojize(":disappointed_face:"),  
    "happy": emoji.emojize(":grinning_face_with_smiling_eyes:"),
    "shine": emoji.emojize(":sparkles:"),
    "danger": emoji.emojize(":skull:"),
    "cry": emoji.emojize(":loudly_crying_face:"),
    "fire": emoji.emojize(":fire:"),
    "hot": emoji.emojize(":fire:"), 
    "sun": emoji.emojize(":sun:"),
    "rain": emoji.emojize(":cloud_with_rain:") 
}

text = input("Enter the text to translate into emojis: ")
words = text.split()


translated_text = " ".join([emoji_dict.get(word, word) for word in words])

print(translated_text)
