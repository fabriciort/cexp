import curses
import time

# Initialize the curses library
curses.initscr()

# Set the cursor to invisible
curses.curs_set(0)

# Set the screen to orange
curses.start_color()
curses.init_pair(1, curses.COLOR_ORANGE, curses.COLOR_BLACK)
curses.attron(curses.color_pair(1))

# Create a list of letters
letters = ["A", "B", "C", "D", "E"]

# Start a loop that will run forever
while True:

    # Clear the screen
    curses.clear()

    # Print the title T.E.L.L in the center of the screen
    curses.addstr(20, 20, "T.E.L.L")

    # Print all the text on the screen
    curses.addstr(25, 30, "The Traveler Enabling Lifeline is a global network of quantum computers that enable time travelers to communicate with their past selves.")
    curses.addstr(30, 40, "The network is controlled by the Director, a super-intelligent AI that is tasked with guiding humanity into a better future.")
    curses.addstr(35, 50, "The Traveler program is a secret government project that recruits people from the past and sends them into the future to prevent catastrophic events from happening.")

    # Refresh the screen
    curses.refresh()

    # Wait for a key press
    key = curses.getch()

    # If the key is the escape key, exit the loop
    if key == 27:
        break

# End the curses library
curses.endwin()
