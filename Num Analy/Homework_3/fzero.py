"""
Erik Sundblad
Program to approximate a given root by Fixed point iteratinon
then report the forward and backward error
9/20/2022
"""


from math import sin

def func(x):
    """ Function for testing y = sin(x**3) - x**3 """
    y = (sin(x**3))**(1/3)
    #y = sin(x**3) - x**3
    return y

def fzero(init):
    """Custom fzero function using fixed point iteration """
    i=0
    x = init
    while(i<1000000):
        x = func(x)
        i += 1
    
    return x

if __name__ == "__main__":
    """Main Function call and driver returns forward and backward values
        for given function with root at 0 
    """
    aprox = fzero(0.1)
    forwardError = abs(0-aprox)
    backwardError = func(aprox)

    #Fancy print statement
    print("For the function y = sin(x**3) - x**3 through our mock fzero's we get.\nFzero Aproximation: {0}\nForward Error: {1}\nBackward Error: {2}".format(aprox, forwardError, backwardError))



