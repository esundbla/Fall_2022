"""
Program to handle LU Decompostion of square matirces
Numerical Anlysis Fall 2022
Erik Sundblad
"""


import os


def decomp(mtx, n):
    """ Decomposition function
    Args:
        mtx: matrix to decompose
        n: size of the matrix (has to be square)
    """
    L = [[0 for y in range(n)] for x in range(n)]  # Initialize both as empty arrays
    U = [[0 for y in range(n)] for x in range(n)]  
    for i in range(n):
        L[i][i] = 1                             # 1's along the diagonal of L
        for j in range(i,n):                    # Loop to fill upper matrix 
            sum = 0
            if i > 0:                           # Python indexing from 0,0 requires special conditions at i=0 range will run on a negative value
                for k in range(i):              # Summation fucntion for given row
                    sum += L[i][k] * U[k][j]
                    #print(sum)
            U[i][j] = mtx[i][j] - sum           # given - value 
        
        for l in range(i+1,n):                  # Loop to fill lower matrix
            sum = 0
            if i > 0:                           # Python indexing from 0,0 requires special conditions at i=0 range will run on a negative value
                for m in range(i):              # Summation loop  
                    sum += L[l][m] * U[m][i]
                    #print(sum)
            L[l][i] = (mtx[l][i]-sum) / U[i][i] # Calulating L values


    return L, U

def matrix_printer(mtx, n):
    """Helper function for fancy print output"""
    for i in range(n):
        for j in range(n):
            print("{:.3f}".format(mtx[i][j]), end="  ")
        print("\n")



if __name__ == "__main__":
    """ Main Driver funtion takes in array and prints out decomp results"""
    while(True):
        n = int(input("Size of the array to decompose: "))
        mtx = [[0 for y in range(n)] for x in range(n)]    #initialize the array of size nxn
        
        #print(mtx)
        #input the matrix 
        for i in range(n):  
            for j in range(n):
                # Fill the array with user assigned values
                mtx[i][j] =  int(input("mtx[{0},{1}] = ".format(i+1,j+1)))
        
        #print(mtx)
        # Run decomposition
        L, U = decomp(mtx, n)

        #Nice output
        print("Original: ")
        matrix_printer(mtx, n)
        print("Lower: ")
        matrix_printer(L,n)
        print("Upper: ")
        matrix_printer(U,n)

        rr = input("\nGo again? (y/n): ")
        if not rr == 'y':
            break

        os.system('cls')
