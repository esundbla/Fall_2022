"""
    Secant
    Program to evaluate given equations set equal to 0 by the secant method
    Erik Sundblad
"""

import os               # For screen clear
from math import exp    # e^(val)
from math import sin    # sin(x)


# Dictionary of functions to try with string representations 
equations = {   
    'a': [lambda x: x**3 -2*x - 2, "x**3 -2*x - 2"],
    'b': [lambda x: exp(x) + x -7, "exp(x) + x -7"],
    'c': [lambda x: exp(x) + sin(x) - 4, "exp(x) + sin(x) - 4"]  
}


def secant(xc, xn, F):
    """
    secant takes in the first two geusses and the equation to itterate over 
    then iterates returning the final held x value (Max Iteration 1 million)
    Arguments:
        xc - current or Xnot the first geusse
        xn - next or second geusee 
        F  - equation chosen to itterate over
    """
    for i in range(1000000):        # Default 1million itterations 
        if F(xn) == 0:              # If we get a 0 on x stop itterating
            print("Found a zero!!!")
            return xn
        xn = (xc*F(xn) - xn*F(xc)) / (F(xn) - F(xc))    #a = (bf(a) - af(b)) / (f(a) - f(b))
    
    # After itterations return current value
    print("Itterated 1,000,000 times!!!")
    return xn
        

if __name__ == "__main__":
    """Main Driver for Scant Program takes user input and runs
        Secant method on chosen equation to approximate the 
        value of X at the root
    """
    # Can re-run program
    while(True):

        print("Equations:")
        for i in equations:
            print("{0}: {1}".format(i, equations[i][1]))
        
        select = input("Equation to run: ")
        
        # Check valid program selection
        while(not equations.keys().__contains__(select)):
            select = input("Invalid selection: ")
        
        # Can modify initial guesses 
        x_0 = float(input("X_0 value: "))
        x_1 = float(input("X_1 value: "))

        # Run actual secant method
        result = secant(x_0, x_1, equations[select][0])

        # Fancy print results and ask to re run or exit
        print("For eq: {0}\nWe get the value: {1}".format(equations[select][1], result))
        rr = input("Go again(y/n)? ")
        if rr != 'y':
            break
        
        os.system('cls')    # On rerun clear screen
 
