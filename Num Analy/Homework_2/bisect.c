#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>



double matrix[][10] = {{1, 2, 3, 4},{4, 5, 6, 6},{7, 7, 8, 9},{10, 10, 11, 12}};
double accuracy;  
double A = 0;
int EQC = 9;        //  [2,3]       [1,2]             [6,7]    [sqrt(A)]     [0,1]        []            [0,1]      [-1,0]          [1,2]
char* EQUATIONS[] = {"x^3-9","(3x^3)+(x^2)-x-5","cos2(x)+6-x","x^2 - A","cos(x)-sin(x)","DET(MTX)","(x^5)+x-1","6x+5-sin(x)","ln(x)+(x^2)-3"};

double det(double si, double mtx[][10]){
    double result = 0;
    if(si < 2){
        printf("error");
        exit(0);
        }
    
    if(si == 2){
        return (mtx[0][0] * mtx[1][1])-(mtx[0][1] * mtx[1][0]); 
    }
    for(int r=0; r < si; r++){
        double newMtx[10][10];
        int mx=0;
        int my=0;
        for(int i=1; i < si; i++){
            for(int j=0; j < si; j++){
               if(j!=r){
                    newMtx[mx][my] = mtx[i][j];
                    my++;
                    if(my > si-2){
                        my=0;
                        mx++;
                    }
               } 

            }
        }
        if(r % 2 == 0){
            result = result + mtx[0][r] * det(si-1, newMtx);
        }else{
            result = result - mtx[0][r] * det(si-1, newMtx);
        }
    }
    return result;
}


double func(double x, int selector){
    double y;
    switch(selector) {
        case 0:
            y = (pow(x, 3))-9;
            break;
        case 1:
            y = (3*pow(x, 3)) + pow(x,2) - x - 5;
            break;
        case 2:
            y = pow(cos(x), 2) + 6 - x;
            break;
        case 3:
            y = pow(x, 2) - A;
            break;
        case 4:
            y = cos(x) - sin(x);
            break;
        case 5:
            matrix[0][3] = x;
            matrix[1][2] = x;
            matrix[2][1] = x;
            matrix[3][0] = x;
            y = det(4, matrix) - 1000;
            printf("DET(%lf) = %lf\n",x, y);
            break;
        case 6:
            y = pow(x,5) + x - 1;
            break;
        case 7:
            y = 6*x + 5 - sin(x);
            break;
        case 8:
            y = log(x) + pow(x,2) - 3;
            break;
        default :
            printf("Chosen eq failed to match selection: %d", selector);
            y = 0;
            break;
    }
    return y;
}

double bisect(double a, double b, double tol, int funcSel){
    double fa, fb, c, fc;
    if(func(a, funcSel)*func(b, funcSel) >= 0){
        printf("A:%lf, and B:%lf do not satisfy f(a)*f(b) <= 0!\n", a, b);
        return false;
    }
    fa = func(a, funcSel);
    fb = func(b, funcSel);

    while((b-a)/2 > tol){
       c = (a+b)/2;
       fc = func(c, funcSel);
       if(fc == 0){
            printf("%lf is the solution", c);
            return c;
        }
        if(fc*fa < 0){
            b = c;
            fb = fc;
        }else{
            a=c;
            fa=fc;
        }
    }
    accuracy = fa - fb;
    return (a+b)/2;
}

int main(){
    
    int selec;
    char rr;
    double tolerance, val, a, b;
    while(true){
        printf("Equations:\n");
        for(int i=0; i < EQC; i++){
            printf("%d: %s\n",i, EQUATIONS[i]);
        }
        printf("Select equation: ");
        scanf("%d", &selec);
        while(selec >= EQC){
            printf("Invalid EQ selection %d must be int 0-%d \n Select Again: ",selec, EQC-1);
            scanf("%d", &selec);
        }
        if(selec == 3){
            printf("Provide Value of A: ");
            scanf("%lf", &A);
        }
        printf("Endpoint A: ");
        scanf("%lf", &a);
        printf("Endpoint B: ");
        scanf("%lf", &b);
        printf("Tolerance: ");
        scanf("%lf", &tolerance);
        
        val = bisect(a, b, tolerance, selec);
        if(!val){
            printf("Try another interval? (y/n) ");
            scanf(" %c", &rr);
            if(rr != 'y'){
                break;
            }else{
                continue;
            }
        }

        printf("For equation = %s,\non interval [%lf, %lf] at tolerance: %lf\n",EQUATIONS[selec], a, b, tolerance);
        printf("Bisect returned: %.8lf\nAcuraccy: %.12lf\nGo again? (y/n)", val, accuracy);
        scanf(" %c", &rr);

        if(rr != 'y') break;
    }
    return 0;
}
