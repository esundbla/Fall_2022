"""
Battery Problem Generator 
Algorithms fall 2022
Erik Sundblad
"""
import random as rand
import string
import matplotlib.pyplot as plt
import numpy as np

path = []

def spin(device):
    offset = rand.randint(0,24) % len(device)
    new_state = [0 for n in range(len(device))]
    for i in range(len(device)):
        new_index = i + offset
        if new_index < len(device):
            new_state[new_index] = device[i]
        else:
            new_state[new_index - len(device)] = device[i]
    
    return new_state     
              

if __name__ == "__main__":
    max =  0      #Positions to check
    results = []
    device = [rand.randint(0,1) for n in range(4) ]
    device =spin(device)
    if device[0] == device[1]:
        device
    
    
    plt.hist(results, bins=50)
    print("The max iterations are: {0}".format(max))
    plt.show()
    