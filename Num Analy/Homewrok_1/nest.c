#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
/*
* Erik Sundblad
* Nest Program for Horner's method polynomial evaluation
* V1.0
*/

double nest(double coef[], double x, double basePoints[], int degree, char base){
    int dec = degree;
    double total;
    if(base == 'y'){
        total  = coef[dec-1] + coef[dec]*(x + basePoints[dec-1]);
    }
    else{
        total = coef[dec-1] + coef[dec]*x;
    }
    dec = dec -2; 
    for(dec; dec >=0; dec--){
        printf("%lf is currently", total);
        if(base == 'y'){
            total  = coef[dec] + (x + basePoints[dec-1])*total;
        }
        else{
            total = coef[dec] + x*total;
        }
    }
    return total;
}

int main() {
    bool run = true;
    while(run){
        int degree;
        double x;
        double coef[30];
        double basePoints[30];
        int counter = 0;
        char basePoint;
        char reRun;

        printf("Enter Degree of Polynomial: ");
        scanf("%d", &degree);
        printf("Basepoints? (y/n): ");
        scanf(" %c", &basePoint);
        
        while(counter <= degree){
            double coefInput;
            double baseInput;
            printf("Enter %d Coeficiant: ", (counter + 1));
            scanf("%lf", &coefInput);
            coef[counter] = coefInput;
            if(basePoint == 'y' && counter < degree){
                //If there are basepoints add them here
                printf("Enter %d basepoint: ", (counter +1));
                scanf("%lf", &baseInput);
                basePoints[counter] = baseInput;
            }
            counter ++;       
        }
        printf("Coeficiants = [ ");
        for(int i=0; i <= degree; i++){
        
        printf("%lf ", coef[i]);
        }
        printf("]\n");
        if(basePoint == 'y'){
            printf("BasePoints = [ ");
            for(int i=0; i < degree; i++){
            
            printf("%lf ", basePoints[i]);
            }
            printf("]\n");
        }
        printf("Degree = %d \n What is the value of X?: ", degree);
        scanf("%lf", &x);
        printf("X = %lf", x);
        double result =  nest(coef, x, basePoints, degree, basePoint);
        double closed = (pow(x, 51)-1)/(x-1);
        printf("\nAt X = %lf the final result = %lf\n Closed: %lf \n Go Again? (y/n):", x, result, closed);
        scanf(" %c", &reRun);
        if(reRun != 'y'){
            run = false;
        }
    }
    return 0;
}