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
    mtx_R = [[0 for x in range(n)]for y in range(n)]
    for k in range(n):
        if mtx[k][k]<0:
            print("Failed Matrix")
            return mtx
        
        mtx_R[k][k] = math.sqrt(mtx[k][k])
        
        u_T = [mtx[k][i]/mtx_R[k][k] for i in range(k+1,n)]
        
        for i in range(k+1,n):
            mtx_R[k][i] = u_T[i-(k+1)]
        
        for i in range(k+1,n):
            for j in range(k+1, n):
                mtx[i][j] = mtx[i][j] - (u_T[i-(k+1)]*u_T[j-(k+1)])
    return mtx_R


if __name__ == "__main__":
    n = int(input("Size of the square matrix: "))
    mtx_A = [[int(input("Location ({0},{1}): ".format(j+1,i+1))) for i in range(n)] for j in range(n)]
    print("\nMatrix A: ")
    mtxPrint(mtx_A)
    mtx_l = cholesky(mtx_A, n)
    print("\nCorresponding R matrix: ")
    mtxPrint(mtx_l)
    print()
