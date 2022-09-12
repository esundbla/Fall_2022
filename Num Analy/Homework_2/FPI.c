#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int EQC = 4; 
char* EQUATIONS[] = {"1-(x^5)","(5-sin(x))/-6","exp(3-(x^2))","(x-e^x-2)^1/3"};
double accuracy;

double func(double x, int selector){
    double y;
    switch(selector) {
        case 0:
            y = 1 - pow(x,5);
            break;
        case 1:
            y = (sin(x) - 5)/6;
            break;
        case 2:
            y = exp(3-pow(x,2));
            break;
        case 3:
            y = cbrt(x-exp(x-2));
            break;
        default :
            printf("Chosen eq failed to match selection: %d", selector);
            y = 0;
            break;
    }
    return y;
}

double fixPointItteration(double x, int iter, int eq){
    double result;
    double y;
    int counter = 0;
    while(true){
        y = func(x, eq);
        x = y;
        if(counter > iter){
            break;
        }
        counter++;

    }
    return x;
}

int main(){
    
    int selec, iter;
    char rr;
    double x, val;
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
        printf("# of iterations: ");
        scanf("%d", &iter);


        val = fixPointItteration(x, iter, selec);

        printf("For equation = %s,\nGiven X=%f for %d itterations\n",EQUATIONS[selec],x, iter);
        printf("FPI returned: %.8lf\nGo again? (y/n)", val);
        scanf(" %c", &rr);

        if(rr != 'y') break;
    }
    return 0;
}
