# Author: Mehul R Shah
# This code is used to take speech input from the user, feed it to GPT-3
# The generated response in the form of speech
# The arduino code is called from here to actuate the servo motors

import pyfirmata
import time
import speech_recognition as sr
import pyttsx3
import serial
import openai
import threading

# Set up OpenAI API credentials
openai.api_key = "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"

# Initialize speech recognition and synthesis engines
r = sr.Recognizer()
engine = pyttsx3.init()

# Set speech rate to 80 percent of original rate
engine.setProperty('rate', engine.getProperty('rate') * 0.8)

# Open serial communication with Arduino
arduino = serial.Serial('COM7', 9600)
time.sleep(2)  # Wait for the connection to establish

while True:
    # Prompt the user to choose between voice input and typing input
    print("Choose input method:")
    print("1. Voice")
    print("2. Typing")
    input_method = input()

    if input_method == "1":
        # Record and process speech input
        with sr.Microphone() as source:
            print("Say something!")
            audio = r.listen(source)
        try:
            text_input = r.recognize_google(audio)
            print("You said: " + text_input)
        except sr.UnknownValueError:
            print("Sorry, I could not understand your speech.")
            continue
        except sr.RequestError as e:
            print("Sorry, could not request results from Google Speech Recognition service: {0}".format(e))
            continue

    elif input_method == "2":
        # Get input from console
        text_input = input("Type a question: ")

    elif input_method == "exit":
        print("Exiting...")
        break

    else:
        print("Invalid input method.")
        continue

    if text_input == "exit":
        print("Exiting...")
        break
    elif text_input == "fear":
        engine.stop()
        arduino.write("1".encode())
    elif text_input == "neutral":
        engine.stop()
        arduino.write("2".encode())
    elif text_input == "sad":
        engine.stop()
        arduino.write("3".encode())
    elif text_input == "angry":
        engine.stop()
        arduino.write("4".encode())
    elif text_input == "surprised":
        engine.stop()
        arduino.write("5".encode())
    elif text_input == "happy":
        engine.stop()
        arduino.write("6".encode())
    elif text_input == "pause":
        engine.stop()
        print("Speech paused.")
    elif text_input == "interrupt":
        print("Interrupting and restarting...")
        break
    else:
        # Feed text to GPT-3 and generate response
        prompt = text_input
        model = "text-davinci-002"
        response = openai.Completion.create(
            engine=model,
            prompt=prompt,
            max_tokens=50
        )
        text_output = response.choices[0].text
        estimated_time = float(len(text_output.split()) / 2.5) * 1.25 # Update estimated time
        print(f"Estimated speech time: {estimated_time} seconds.")
        print("GPT-3: " + text_output)

        # Send the estimated speech time to Arduino
        arduino.write("{:.1f}".format(estimated_time).encode())
        # Convert response to voice signal and play it back
        time.sleep(2)
        engine.say(text_output)
        engine.runAndWait()

# Clean up
engine.stop()

