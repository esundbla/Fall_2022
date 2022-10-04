def func(x):
    y = x**3 - 2*x -2 
    return y


def regulaFalsi(a,b, tol, max_i):
    for i in range(max_i):
        c = (b*func(a) - a*func(b))/(func(a)- func(b))
        
        if func(c) == 0:
            return c
        """elif func(c) < tol:
            print("hit the tolerance")
            return c
        """
        if func(a)*func(c) < 0:
            b=c
        else:
            a=c
    
    print("Went through all iterations")
    return c

if __name__ == "__main__":
   result = regulaFalsi(1,2, .0000001, 1000)
   print("We get the value {0}".format(result)) 
    
        