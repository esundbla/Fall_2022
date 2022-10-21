"""
Finalized battery algorithm code generator 
Algorithms Fall 2022
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


def algorithm(device, step):
    if step == 1:
        peek_1, peek_2 = 0,1 #Ajencent peek
        if device[peek_1] == device[peek_2]:
            device[peek_1], device[peek_2] = 1,1 #both to p
        else:
            if device[peek_1] == 0:              #p->n
                device[peek_1] = 1
            else:
                device[peek_2] = 1
        return device
    
    elif step == 2:
        peek_1, peek_2 = 0,2    #Opposite peek
        if device[peek_1] == device[peek_2]:
            device[peek_1], device[peek_2] = 1,1 #both to p
        else:
            if device[peek_1] == 0:              ##p->n
                device[peek_1] = 1
            else:
                device[peek_2] = 1
        return device
    
    elif step == 3:
        peek_1, peek_2 = 0,2   #Opposite peek     
        if device[peek_1] == device[peek_2]:
            device[peek_1], device[peek_2] = 1,0 #Set 1 p to n
        else:
            if device[peek_1] == 0:              ##p->n
                device[peek_1] = 1
            else:
                device[peek_2] = 1
        return device
    
    elif step == 4:
        peek_1, peek_2 = 0,1 #Ajencent peek
        device[peek_1], device[peek_2] = (device[peek_1] +1)%2, (device[peek_2]+1)%2 # Flip both
        return device
    
    elif step == 5:
        peek_1, peek_2 = 0,2   #Opposite peek
        device[peek_1], device[peek_2] = (device[peek_1] +1)%2, (device[peek_2]+1)%2 # Flip both
        return device
    
    else:
        print("Algortihm Failed")
        print(device)
        exit(1)


if __name__ == "__main__":
    for i in range(20):
        counter = 0
        device = [rand.randint(0,1) for n in range(4) ]
        #print(device)
        
        while(True):
            if not device.__contains__(1) or not device.__contains__(0):
                break
            counter += 1
            device  = algorithm(device, counter)
            #print(device)
            device = spin(device)
        
        print("The final state of the device = " + str(device))
        print("After {0} itterations".format(counter))
