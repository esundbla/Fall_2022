#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int EQC = 3;        //  [2,3]       [1,2]             [6,7]
char* EQUATIONS[] = {"x^3-9","(3x^3)+(x^2)-x-5","cos2(x)+6-x"};

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
        printf("A:%lf, and B:%lf do not satisfy f(a)*f(b) <= 0!", a, b);
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
        printf("Endpoint A: ");
        scanf("%lf", &a);
        printf("Endpoint B: ");
        scanf("%lf", &b);
        printf("Tolerance: ");
        scanf("%lf", &tolerance);
        
        val = bisect(a, b, tolerance, selec);

        printf("For equation = %s,\non interval [%lf, %lf] at tolerance: %lf\n",EQUATIONS[selec], a, b, tolerance);
        printf("Bisect returned: %lf\nGo again? (y/n)", val);
        scanf(" %c", &rr);

        if(rr != 'y') break;
    }
    return 0;
}
