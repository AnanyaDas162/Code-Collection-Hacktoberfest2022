import pyttsx3
import datetime
import speech_recognition as sr
import wikipedia
import webbrowser
import os
engine=pyttsx3.init('sapi5')


# there is two voices in my system 1 for Zira , 0 for David in both
voices = engine.getProperty('voices')
#print(voices[0].id)
engine.setProperty('voice',voices[0].id)


def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour>=0 and hour<12:
        speak("Very Good Morning  Sir!!")

    elif hour>=12 and hour<18:
        speak("Good After Noon Sir")
    else:
        speak("Good Evening!!")

    speak("I am Jarvis 0.1 , How may i assist you")
  
def takeCommand():
    # It takes microphone input from the user and returns string output

    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        r.adjust_for_ambient_noise(source,duration=1)
        audio = r.listen(source)
        

    try:
        print("Recognizing...")    
        query = r.recognize_google(audio, language='en-in') #Using google for voice recognition.
        print(f"User said: {query}\n")  #User query will be printed.

    except Exception as e:
        # print(e)    
        print("Say that again please...")   #Say that again will be printed in case of improper voice 
        return "None" #None string will be returned
    return query       



if __name__=="__main__":
    wishMe()
    while True:
      query = takeCommand().lower()

      #logic for executing tasks based on query
      if 'wikipedia' in query:
        speak('Searching request..........')
        query = query.replace("wikipedia", "")
        results = wikipedia.summary(query, sentences=2)
        speak("Sir!! According to search Results")
        print(results)
        speak(results)

         #plants according to Wikipedia
         #taj mahal as wikipedia
         #India as wikipedia
      elif 'open youtube' in query:
        webbrowser.open("https://www.youtube.com")

      
      elif 'google' in query:
        webbrowser.open("https://www.google.com")

      elif 'open Hacktoberfest' in query:
        webbrowser.open("https://hacktoberfest.com/participation/")

      elif 'open linkedin' in query:
        webbrowser.open("https://www.linkedin.com/feed/")
    

      elif 'Introduce yourself' in query:
        speak('Hello!!! Everyone I will be your ,assistant able to perform  minor tasks on your voice command!!, I am designed on Python!! , I will be happy to assist you.')
        
      #elif 'any message before' in query:
        #speak(' Yessss!! Plz Subscribe!!! Tech Vine to see more cool contents like this!! ok Sir!! we can start')
      
      ## for music
      #elif 'long day' in query:
        #speak('Yes Sir!! Would you like to relax')
      elif 'music' in query:
        speak('Playing relaxing music !! Sit back and Relax')
        music='D:\\Music relax'
        songs = os.listdir(music)
        os.startfile(os.path.join(music, songs[0]))

      elif 'joke' in query:
        speak('Why are math books so darn depressing?')
      elif 'why' in query:
        speak(' because They’re literally filled with problems.')

      elif 'time'in query:
       strtime= datetime.datetime.now().strftime("%H:%M")
       speak(f"sir!! the time is {strtime}")

      elif 'open pycharm' in query:
        pycharmpath= "C:\\Program Files\\JetBrains\\PyCharm Community Edition 2021.3\\bin\\pycharm64.exe"
        os.startfile(pycharmpath)
      elif 'virtualbox' in query:
        virtualboxpath= "C:\\Program Files\\Oracle\\VirtualBox\\VirtualBox.exe"
        os.startfile(virtualboxpath)
