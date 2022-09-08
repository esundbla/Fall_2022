#include <stdio.h>

double matrix[][10] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};

double det(double si, double mtx[][10]){
    double result = 0;
    if(si < 2){
        printf("error");\
        exit(0);
        }
    
    if(si == 2){
        printf("[%f, %f]\n[%f,%f]\n",mtx[0][0], mtx[0][1], mtx[1][0], mtx[1][1]);
        double val = (mtx[0][0] * mtx[1][1])-(mtx[0][1] * mtx[1][0]); 
        printf(" det minor = %lf\n",val);
        return val;
    }
    for(int r=0; r < si; r++){
        double newMtx[10][10];
        int my=0;
        int mx=0;
        for(int i=1; i < si; i++){
            for(int j=0; j < si; j++){
               if(j!=r){
                    printf("New matrix element [%d][%d] = %lf\n", mx, my, mtx[i][j]);
                    newMtx[mx][my] = mtx[i][j];
                    my++;
                    if(my > si-2){
                        my=0;
                        mx++;
                    }
               } 

            }
        }
        if(r % 2 == 1){
            result = result + mtx[0][r] * det(si-1, newMtx);
        }else{
            result = result - mtx[0][r] * det(si-1, newMtx);
        }
    }
    return result;
}

int main(){
    double result = det(3, matrix);
    printf("results: %lf\n",result);
}