from cs50 import get_string
import random

x = random.randint(10, 50)
name = get_string("What is your name? ")
print(f"Your name is {name} your age is {x}")
