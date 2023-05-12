import sys
import random
import colorama

colorama.init(autoreset=True)

# Create a list of responses.
responses = ["Hello there!", "Goodbye!", "What's your name?", "Who are you?"]

# Create a prompt bar.
prompt = "\nWhat would you like to say?\n"
prompt += "> "

# Get the user's input.
user_input = input(prompt)

# Check if the user's input is in the list of responses.
if user_input in responses:
    # If the input is in the list, print the corresponding response.
    print(colorama.Fore.GREEN + responses[user_input] + colorama.Fore.RESET)
else:
    # If the input is not in the list, print a default response.
    print(colorama.Fore.RED + "I don't understand." + colorama.Fore.RESET)

# If the user enters "quit", exit the program.
if user_input == "quit":
    sys.exit()

# Loop until the user enters "quit".
while True:
    user_input = input(prompt)

    # Check if the user's input is in the list of responses.
    if user_input in responses:
        # If the input is in the list, print the corresponding response.
        print(colorama.Fore.GREEN + responses[user_input] + colorama.Fore.RESET)
    else:
        # If the input is not in the list, print a default response.
        print(colorama.Fore.RED + "I don't understand." + colorama.Fore.RESET)

    # If the user enters "quit", exit the program.
    if user_input == "quit":
        sys.exit()

