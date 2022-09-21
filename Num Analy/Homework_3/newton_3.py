"""
Erik Sundblad
Program to utilize newtons method to approximate roots of given functions
Then use the modified method to do the same
report results and forward/backward error
"""

TrueRootA = (-2/3) #For Error Calculations
TrueRootB = (1/6)

def funcA(x, mod):
    """ Function A from problem 3"""
    if not mod:
        y = x - ((27*(x**3) + 54*(x**2) + 36*x + 8) / (81*(x**2) + 108*x + 36))
    else:
        # Has a multiplicity of 2
        y = x - 2*((27*(x**3) + 54*(x**2) + 36*x + 8) / (81*(x**2) + 108*x + 36))
    return y


def funcB(x, mod):
    """ Function B from problem 3"""
    if not mod:
        y = x - ((36*(x**4) - 12*(x**3) + 37*(x**2) - 12*x + 1) / (144*(x**3) - 36*(x**2) + 74*x - 12))
    else:
        # Has a multiplicity of 2 for modified newtons
        y = x - 2*((36*(x**4) - 12*(x**3) + 37*(x**2) - 12*x + 1) / (144*(x**3) - 36*(x**2) + 74*x - 12))
    return y


def newtons(init, mod, A):
    """ Can be modified or not newtons method """
    x = init #Take in the first geuse
    while True:
        old_x = x
        if A:                   #Do A or b based on A or not A 
            x = funcA(x, mod)
        else:
            x = funcB(x, mod)
    
        if old_x-x == 0:       #Value no longer changes per itteration
            break
    if A:
        return x, abs(x-trueRootA), funcA(x, mod)   #Return coresponding to A or B
    else:
        return x, abs(x-trueRootB), funcB(x, mod)
        


if __name__ == "__main__":
    trueRootA = (-2/3)
    trueRootB = (1/6)

    rootA, forwardA, backwardA = newtons(0, False, True) #Run unmoded look for value A
    rootB, forwardB, backwardB = newtons(0, False, False)  #Run unmoded look for value B

    mrootA, mforwardA, mbackwardA = newtons(0, True, True) #Run moded look for value A
    mrootB, mforwardB, mbackwardB = newtons(0, True, False)  #Run moded look for value B


    print("For equation A newtons method returned {0} With forward error {1} and backward error {2}".format(rootA, forwardA, backwardA))
    print("For equation B newtons method returned {0} With forward error {1} and backward error {2}".format(rootB, forwardB, backwardB))

    print("*"*300)

    print("For equation A newtons moddified method returned {0} With forward error {1} and backward error {2}".format(mrootA, mforwardA, mbackwardA))
    print("For equation B newtons moddified method returned {0} With forward error {1} and backward error {2}".format(mrootB, mforwardB, mbackwardB))



    
