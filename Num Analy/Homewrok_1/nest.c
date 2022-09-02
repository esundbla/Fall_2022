#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
/*
* Erik Sundblad
* Nest Program for Horner's method polynomial evaluation
* 9/1/2022
*/

double nest(double coef[], double x, double basePoints[], int degree, char base){
    //Nest program to return double value after comleting nested evalutation
    int dec = degree;
    double total;
    //Base point check requires slight change to algorithm
    if(base == 'y'){
        total  = coef[dec-1] + coef[dec]*(x + basePoints[dec-1]);
    }
    else{
        total = coef[dec-1] + coef[dec]*x;
    }
    dec = dec -2; //Convention to handle 1st and 0 index issues
    for(dec; dec >=0; dec--){
        //loop through given coefficiants solving nest
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
        /* Main function variabl decleration max coef degree = 300 */
        int degree;             
        double x;
        double coef[300];
        double basePoints[300];
        int counter = 0;

        /* basepoint check, rerun call, padding all 1's, oscilating check */
        char basePoint;
        char reRun;
        char pad;
        char osc;

        /* Take in necissary check charecters */
        printf("Enter Degree of Polynomial: ");
        scanf("%d", &degree);
        printf("Basepoints? (y/n): ");
        scanf(" %c", &basePoint);
        printf("Use all 1's for coef? (y/n): ");
        scanf(" %c", &pad);
        if(pad == 'y'){                 //Only Oscilate if Padding
            printf("Oscillating? ");
            scanf(" %c", &osc);
        }
                
        while(counter <= degree){   
            /* Loop to ask user for coeficiants & base Points or fill with padded 1's  */
            double coefInput; 
            double baseInput;
            if(pad != 'y'){ //if not padding then ask user for coeficiant 
                printf("Enter %d Coeficiant: ", (counter + 1));
                scanf("%lf", &coefInput);
                coef[counter] = coefInput;
            }else{
                if(osc == 'y' && counter % 2 != 0){  //if padding and oscilating then set odd position coef = -1 
                    coef[counter] = -1;
                }else{
                    coef[counter] = 1; //if not padding or an even position coef =1
                }
            }
            if(basePoint == 'y' && counter < degree){ //Grab basepoints if specified
                //If there are basepoints add them here
                printf("Enter %d basepoint: ", (counter +1));
                scanf("%lf", &baseInput);
                basePoints[counter] = baseInput;
            }
            counter ++;       
        }
        /* Print coeficiants and Basepoints get the value of X */ 
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

        /* Pass Variables to nest  (listed above) and store returned result */
        double result =  nest(coef, x, basePoints, degree, basePoint);
        
        /* Calculate closed form of given summations and store results */
        double closed;
        if(osc == 'y'){
            closed = ((1-(pow(pow(x, 2), 50)))/(1-pow(x, 2)))*(1-x); //((1-(x^2)^50)/(1-x^2))*(1-x)
        }else{
            closed = (pow(x, 51)-1)/(x-1);
        }

        /* Print final results and ask to re-run the program otherwise exit */
        printf("\nAt X = %lf the final result = %.52lf\n", x, result);
        printf("closed form result = %.52lf\n Difference= %.52lf\n", closed, (result - closed));
        printf("go Again? (y/n):");
        
        scanf(" %c", &reRun);
        if(reRun != 'y'){
            run = false;
        }
    }
    return 0;
}