"""
Battery Problem Generator 
Algorithms fall 2022
Erik Sundblad
"""
import random as rand
import matplotlib.pyplot as plt
import numpy as np


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
    first, second, max = 0, 1, 0      #Positions to check
    results = []
    #Loop till we get goal orrientation
    for r in range(10000000):
        device = [rand.randint(0,1) for n in range(4) ]
        counter = 0
        while(True):
            device = spin(device)
            #print(device)
            if not device.__contains__(1) or not device.__contains__(0):
                break
                power = True
            device[first] = 1
            device[second] = 1
            counter = counter +  1
        
        if max < counter:
            max = counter
        results.append(counter)
    
    
    x = [float(x) for x in range(2)]
    #hist = np.histogram(results, bins=5)
    plt.hist(results, bins=50)
    print("The max iterations are: {0}".format(max))
    plt.show()
    