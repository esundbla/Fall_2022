#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>
#include <string.h>



int EQC = 5; 
char* EQUATIONS[] = {"1-(x^5)","(5-sin(x))/-6","exp(3-(x^2))","(x-e^x-2)^1/3","((10/3)*pow(x,2) + (2/3)*pow(x,3))/((20/3)*x + 2*pow(x,2)"};
double accuracy;


int EQC = 13;  //Variable holds count of equations used


/* String representation of equations for output and user selection */
char* EQUATIONS[] = {"1-(x^5)","(5-sin(x))/-6","exp(3-(x^2))","(x-e^x-2)^1/3",
                     "cbrt((1+6x)/2)","(2x^3 -1)/6","1/(2x^2-6)",
                     "e^(x-2)+x^3","ln(x-x^3)-2","cbrt(x-e^(x-2))",
                     "(1/5)(6x^3 + e^2x -1)","cbrt((1+5x-e^2x)/6)","ln(1+5x-6x^3)/2"};
double accuracy;

/*
*Function implements provided equations and holds switch statement to select 
*returns a double of the output of given eq.
*/
double func(double x, int selector){
    double y;
    switch(selector) {
        case 0:
            y = 1 - pow(x,5);       //1.2 Q2 part a
            break;
        case 1:
            y = (sin(x) - 5)/6;     //1.2 Q2 part b
            break;
        case 2:
            y = exp(3-pow(x,2));    //1.2 Q2 part c
            break;
        case 3:
            y = cbrt(x-exp(x-2));   //testing
            break;
        case 4:
            y = cbrt((1 + 6*x)/2);  //1.2 Q3 part a1
            break;
        case 5:
            y = (2*pow(x,3)-1)/6;   //1.2 Q3 part a2
            break;
        case 6:
            y = 1/(2*pow(x,2)-6);   //1.2 Q3 part a3
            break;
        case 7:
            y = exp(x-2)+pow(x,3);  //1.2 Q3 part b1
            break;
        case 8:
            y = log(x-pow(x,3))-2;  //1.2 Q3 part b2
            break;
        case 9:
            y = cbrt(x-exp(x-2));   //1.2 Q3 part b3
            break;
        case 10:
            y = (6/5)*(pow(x,3)+exp(2*x)-1);    //1.2 Q3 part c1
            break;
        case 11:
            y = cbrt((1+5*x-exp(2*x))/6);   //1.2 Q3 part c2
            break;
        case 12:
            y = log(1+5*x-6*pow(x,3))/2;    //1.2 Q3 part c3
            break;
        case 4:
            y = x - (((((10/3)*M_PI*pow(x,2)) + ((2/3)*M_PI*pow(x,3)))-60) / (((20/3)*M_PI*x) + (2*M_PI*pow(x,2))));
            break;
        default :
            printf("Chosen eq failed to match selection: %d", selector);
            y = 0;
            break;
    }
    return y;
}

/*
*Fixed Point Itteration function implimentation 
*/
double fixPointItteration(double x, int iter, int eq){
    double result;
    double y;
    int counter = 0;
    while(true){
        y = func(x, eq);
        x = y;
        printf("%lf\n", x);
        if(counter > iter){
            break;
        }
        counter++;

    }
    return x;
}

/*
*main function body takes in values to run through Fixed Point Itterator based on given equation
*fancy prints results can be re-ran and clears screen between
*/
int main(){
    
    int selec, iter;    //function selector and iteration count
    char rr;            //re-reun char
    double x, val;      //input x and final Val
    while(true){
        printf("Equations:\n");
        for(int i=0; i < EQC; i++){
            if(i==4){
                printf("The next set of equations are for question 6\n"); //Start equations for Q6
                printf("The next three are for the f(x)= 2x^3-6x+1\n");   //Part A
            }else if(i==7){
                printf("The next three are for the f(x)= e^(x-2) +x^3 -x\n"); // Part B
            }else if(i==10){
                printf("The next three are for the f(x)= 1 + 5x - 6x^3 - e^2x\n"); // Part C
            }
            printf("%d: %s\n",i, EQUATIONS[i]);
        }
        printf("Select equation: ");
        scanf("%d", &selec);
        while(selec >= EQC){
            printf("Invalid EQ selection %d must be int 0-%d \n Select Again: ",selec, EQC-1); //Checking valid input
            scanf("%d", &selec);
        }
        printf("Initial X: ");
        scanf("%lf", &x);
        printf("# of iterations: ");
        scanf("%d", &iter);


        val = fixPointItteration(x, iter, selec); //run FPI

        printf("For equation = %s,\nGiven X=%f for %d itterations\n",EQUATIONS[selec],x, iter);
        printf("FM_PI returned: %.8lf\nGo again? (y/n)", val);
        scanf(" %c", &rr);

        if(rr != 'y') break; //Re-run 
        system("cls");
    }
    return 0;
}
