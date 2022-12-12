"""
    Cholesky Factorization in python
    Numerical Analysis fall 2022
    Erik Sundblad
"""
import math


def mtxPrint(mtx):
    """Fancy print for Matrix lists"""
    print()
    for i in range(len(mtx)):
        for j in range(len(mtx)):
            print(mtx[i][j], end='  ')
        print()


def cholesky(mtx, n):
    """Run cholesky's algorithm on square matrix"""
    mtx_R = [[0 for x in range(n)]for y in range(n)]    #initialize R as a matrix of zeros
    for k in range(n):                                  #for k in n where n is the size of the matrix
        if mtx[k][k]<0:                                 #if we get a negative value we cant use this method
            print("Failed Matrix")
            exit(1)  
            return mtx
        
        mtx_R[k][k] = math.sqrt(mtx[k][k])              #get top left value
        
        u_T = [mtx[k][i]/mtx_R[k][k] for i in range(k+1,n)]     #coresponding vector 
        
        for i in range(k+1,n):
            mtx_R[k][i] = u_T[i-(k+1)]                          #add u_T into our R matrix
        
        for i in range(k+1,n):                                  #modify the A matrix by the outer product of the u_T vector
            for j in range(k+1, n):
                mtx[i][j] = mtx[i][j] - (u_T[i-(k+1)]*u_T[j-(k+1)]) 
        
        """ 
        #debugging print to monitor changes every iteration
        print("Step {0} matrices".format(k))
        print("A: ")
        mtxPrint(mtx)
        print("R: ")
        mtxPrint(mtx_R)
        """
    return mtx_R


if __name__ == "__main__":
    """Main driver function takes in a square matrix of size n
       Runs the cholesky method and outputs the coresponding R matrix
    """

    n = int(input("Size of the square matrix: "))  # Get size of matrix
    
    #List comprehension to build our A matrix based on user input
    mtx_A = [[int(input("Location ({0},{1}): ".format(j+1,i+1))) for i in range(n)] for j in range(n)]
    
    #print given matrix
    print("Matrix A: ")
    mtxPrint(mtx_A)

    #run cholesky
    mtx_l = cholesky(mtx_A, n)

    #print coresponding R
    print("Corresponding R matrix: ")
    mtxPrint(mtx_l)
