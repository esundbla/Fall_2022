/*
 Significance
 Program demonstrating acuracy as x->0 
 Erik Sundblad
 9/1/2022
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int main(){
    /* Main Variable Decleration */
    double VAL = (1.0/3.0); //Limit as x->0
    int expo;               //exponential 'P'
    double x;               // = 10^-p               
    char part;              //part char decides which part rrun decides rerun 
    char rrun;
    double result;          //result of calc - (1/3)
    bool run = true;        

    printf("Part? (a/b):");
    scanf(" %c", &part);
    
    while(run){
        printf("Value of p?: ");    //Get the value of P
        scanf("%d", &expo);
        x = pow(10, -expo);
        double calc;

        if(part == 'a'){
            //Calcualte tanx -x over x^3 print and return results comparing to (1/3)
            calc = (tan(x)-x)/pow(x, 3);
            result = calc - VAL;
            printf("Caluclated: %.52lf\nActual:  %.52lf\nDifference: %.52lf", calc, VAL, result);
            printf("Run Again? (y/n):");
            scanf(" %c", &rrun);
            if(rrun != 'y'){
                run = false;
            }
        }else if(part == 'b'){
            //Calculate e^x +cosX -sinX -2 over x^3 print and return results comparing to (1/3) 
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