#!/usr/bin/env python3
# Import required libraries
import tkinter as tk          # For creating the GUI window
import RPi.GPIO as GPIO       # For controlling Raspberry Pi GPIO pins

# Set GPIO numbering mode to BCM (Broadcom SOC channel)
GPIO.setmode(GPIO.BCM)

# Define GPIO pin numbers for LEDs
RED = 5
YELLOW = 6
GREEN = 13

# Configure pins as output
GPIO.setup(RED, GPIO.OUT)
GPIO.setup(YELLOW, GPIO.OUT)
GPIO.setup(GREEN, GPIO.OUT)

# Initially turn off all LEDs
GPIO.output(RED, GPIO.LOW)
GPIO.output(YELLOW, GPIO.LOW)
GPIO.output(GREEN, GPIO.LOW)

# Function to turn ON red LED and turn OFF others
def turn_on_red():
    GPIO.output(RED, GPIO.HIGH)      # Red ON
    GPIO.output(YELLOW, GPIO.LOW)    # Yellow OFF
    GPIO.output(GREEN, GPIO.LOW)     # Green OFF

# Function to turn ON yellow LED and turn OFF others
def turn_on_yellow():
    GPIO.output(RED, GPIO.LOW)       # Red OFF
    GPIO.output(YELLOW, GPIO.HIGH)   # Yellow ON
    GPIO.output(GREEN, GPIO.LOW)     # Green OFF

# Function to turn ON green LED and turn OFF others
def turn_on_green():
    GPIO.output(RED, GPIO.LOW)       # Red OFF
    GPIO.output(YELLOW, GPIO.LOW)    # Yellow OFF
    GPIO.output(GREEN, GPIO.HIGH)    # Green ON

# Function to turn OFF all LEDs
def turn_off_all():
    GPIO.output(RED, GPIO.LOW)
    GPIO.output(YELLOW, GPIO.LOW)
    GPIO.output(GREEN, GPIO.LOW)

# Function to safely exit the program
def close_program():
    turn_off_all()       # Make sure all LEDs are OFF
    GPIO.cleanup()       # Release GPIO resources
    root.destroy()       # Close the GUI window

# Create the main GUI window
root = tk.Tk()
root.title("LED Control")

# Add a label at the top of the window
label = tk.Label(root, text="Click a button to turn ON an LED:")
label.pack(pady=10)

# Create buttons for each LED and their respective functions
btn_red = tk.Button(root, text="Red LED", command=turn_on_red)
btn_red.pack(fill="x", padx=20, pady=5)

btn_yellow = tk.Button(root, text="Yellow LED", command=turn_on_yellow)
btn_yellow.pack(fill="x", padx=20, pady=5)

btn_green = tk.Button(root, text="Green LED", command=turn_on_green)
btn_green.pack(fill="x", padx=20, pady=5)

# Button to turn OFF all LEDs
btn_off = tk.Button(root, text="Turn OFF All LEDs", command=turn_off_all)
btn_off.pack(fill="x", padx=20, pady=5)

# Exit button to close program safely
btn_exit = tk.Button(root, text="Exit", command=close_program)
btn_exit.pack(fill="x", padx=20, pady=10)

# Handle window close button (X) properly
root.protocol("WM_DELETE_WINDOW", close_program)

# Run the GUI event loop
root.mainloop()
