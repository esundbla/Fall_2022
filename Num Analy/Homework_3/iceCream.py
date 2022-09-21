""""
Erik Sundblad
Program to using newtons method to approximate the radius of a 
cone with a known volume of ice cream
"""

from math import pi


def func(x):
    """Ice Cream cone Area function set to 0
       The evaluated to get the radius r
    """
    y = x - ((pi*(x**2)*(10/3) + (2/3)*pi*(x**3))-60) / (2*pi*x*(10/3) + 2*pi*(x**2))
    return y


def newtons(init):
    """ Newtons method itterates until it gets no closer to an answer"""
    x = init
    i = 0
    while i<10000 :      #Gets a pretty good estimate
        x = func(x)
        i += 1
    return x


if __name__ == "__main__":
    radius = newtons(2)
    print("The radius calculated starting at 2 of the Ice Cream Cone is {0}".format(radius))