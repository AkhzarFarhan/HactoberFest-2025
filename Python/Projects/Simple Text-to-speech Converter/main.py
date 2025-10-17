from gtts import gTTS
import os

mytext = input('Enter the Text to convert: ')

#convert to english
language = 'en'

obj = gTTS(text=mytext, lang=language, slow=False)

#output file stored in the same folder 
obj.save("output.mp3")
#output file playing
os.system('output.mp3')
