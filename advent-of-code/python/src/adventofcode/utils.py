import sys

def readInput(name):
    filename = "input/" + name + ".txt"
    with open(filename, 'r') as f:
        lines = f.read().splitlines()
    return lines

def log(*args):
    print(args)