#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int main(){
    double VAL = (1.0/3.0);
    int expo;
    double x;
    char part;
    char rrun;
    double result;
    bool run = true;
    
    printf("Part? (a/b):");
    scanf(" %c", &part);
    
    while(run){
        printf("Value of p?: ");
        scanf("%d", &expo);
        x = pow(10, -expo);
        double calc;

        if(part == 'a'){
            calc = (tan(x)-x)/pow(x, 3);
            result = calc - VAL;
            printf("Caluclated: %.52lf\nActual:  %.52lf\nDifference: %.52lf", calc, VAL, result);
            printf("Run Again? (y/n):");
            scanf(" %c", &rrun);
            if(rrun != 'y'){
                run = false;
            }
        }else if(part == 'b'){
            calc = (exp(x)+cos(x)-sin(x)-2)/pow(x, 3);
            result = calc - VAL;
            printf("Caluclated: %.52lf\nActual:  %.52lf\nDifference: %.52lf\n", calc, VAL, result);
            printf("Run Again? (y/n):");
            scanf(" %c", &rrun);
            if(rrun != 'y'){
                run = false;
            }
        }
    }  
    return 0;
}