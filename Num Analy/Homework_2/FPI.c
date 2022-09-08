#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int EQC = 3; 
char* EQUATIONS[] = {"(x^5)+x-1","6x+5-sin(x)","ln(x)+(x^2)-3"};
double accuracy;

double func(double x, int selector){
    double y;
    switch(selector) {
        case 0:
            y = pow(x,5) + x - 1;
            break;
        case 1:
            y = 6*x + 5 - sin(x);
            break;
        case 2:
            y = log(x) + pow(x,2) - 3;
            break;
        default :
            printf("Chosen eq failed to match selection: %d", selector);
            y = 0;
            break;
    }
    return y;
}

double fixPointItteration(double x, double tol, int eq){
    double result;
    double y = INFINITY;
    int counter = 0;
    while( y  > tol){
        y = func(x, eq);
        x = y;
        if(counter > 100){
            break;
        }
        counter++;

    }
    return x;
}

int main(){
    
    int selec;
    char rr;
    double tolerance, x, val;
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
        printf("Initial X: ");
        scanf("%lf", &x);
        printf("Tolerance: ");
        scanf("%lf", &tolerance);

        printf("For equation = %s,\nGiven X=%f at tolerance: %lf\n",EQUATIONS[selec],x, tolerance);
        printf("FPI returned: %.8lf\nAcuraccy: %.12lf\nGo again? (y/n)", val, accuracy);
        scanf(" %c", &rr);

        if(rr != 'y') break;
    }
    return 0;
}
