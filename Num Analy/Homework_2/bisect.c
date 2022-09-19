#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>



double matrix[][10] = {{1, 2, 3, 4},{4, 5, 6, 6},{7, 7, 8, 9},{10, 10, 11, 12}};    //Matrix for 1.1 Q.7
double accuracy;  
double A = 0;   //Variable to hold sqrt(A) value
int EQC = 9;        //  [2,3]       [1,2]             [6,7]    [sqrt(A)]     [0,1]        []            [0,1]      [-1,0]          [1,2]  <-Found intervals of exectution
char* EQUATIONS[] = {"x^3-9","(3x^3)+(x^2)-x-5","cos2(x)+6-x","x^2 - A","cos(x)-sin(x)","DET(MTX)","(x^5)+x-1","6x+5-sin(x)","ln(x)+(x^2)-3"};
//Equations to be run as bisect 


/*
*Det function uses square matrix of given size si
*Recursively breaks down matrix till 2x2 and then returns base DET
*/
double det(double si, double mtx[][10]){
    double result = 0;
    if(si < 2){                                                     //Base Case size < 2 not possible 
        printf("error");
        exit(0);
        }
    
    if(si == 2){
        return (mtx[0][0] * mtx[1][1])-(mtx[0][1] * mtx[1][0]);     //Base case mtx is 2x2 therefore calculate!
    }
    for(int r=0; r < si; r++){                                      //Loop through neciscary number of sub-matrices to be formed
        double newMtx[10][10];
        int mx=0;               //New Matrix x position
        int my=0;               //New Matrix y position
        for(int i=1; i < si; i++){                          //Loop through rows
            for(int j=0; j < si; j++){                      //Loop through columns
               if(j!=r){                                    //Sub-matrix will not inclued the column of curent multiplier
                    newMtx[mx][my] = mtx[i][j];             //set values in new matrix
                    my++;           //Incriment postion to set new
                    if(my > si-2){  //rollover to next row in new matrix when cur row is full
                        my=0;
                        mx++;
                    }
               } 

            }
        }
        if(r % 2 == 0){                                         //Modulus to create add or subtraction based number of sub-matirces 
            result = result + mtx[0][r] * det(si-1, newMtx);    //Recursive call on new sub-matrix 
        }else{
            result = result - mtx[0][r] * det(si-1, newMtx);
        }
    }
    return result;
}

/*
*function to execute selected function and return value of y
*/
double func(double x, int selector){
    double y;
    switch(selector) {
        case 0:
            y = (pow(x, 3))-9;                          //1.1 Q1 a
            break;
        case 1:
            y = (3*pow(x, 3)) + pow(x,2) - x - 5;       //1.1 Q1 b
            break;
        case 2:
            y = pow(cos(x), 2) + 6 - x;                 //1.1 Q1 c
            break;
        case 3:
            y = pow(x, 2) - A;                          //1.1 Q4 
            break;
        case 4:
            y = cos(x) - sin(x);                        //1.1 Q6
            break;
        case 5:                                     
            matrix[0][3] = x;
            matrix[1][2] = x;
            matrix[2][1] = x;
            matrix[3][0] = x;
            y = det(4, matrix) - 1000;                 //1.1 Q7
            printf("DET(%lf) = %lf\n",x, y);
            break;
        case 6:
        y = pow(x,5) + x - 1;                      //1.1 Q2 a
            break;
        case 7:
            y = 6*x + 5 - sin(x);                  //1.1 Q2 b
            break;
        case 8:
            y = log(x) + pow(x,2) - 3;              //1.1 Q2 C
            break;
        default :
            printf("Chosen eq failed to match selection: %d", selector);
            y = 0;
            break;
    }
    return y;
}


/*
*Bisect method given in book implimentation
*/
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
    
    accuracy = fa - fb;     //acuracy as a difference of function for personal investigation
    return (a+b)/2;
}

/*
*Main function driver takes input on equation selection
*additional functionality when necissary such as square root problem 
*can re-run and clear screen
*/
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
        if(selec == 3){                     //scan in value of a for square root problem 
            printf("Provide Value of A: ");
            scanf("%lf", &A);
        }
        printf("Endpoint A: ");
        scanf("%lf", &a);
        printf("Endpoint B: ");
        scanf("%lf", &b);
        printf("Tolerance: ");
        scanf("%lf", &tolerance);
        
        val = bisect(a, b, tolerance, selec);           //if val is false(didn't satisfy f(a)*f(b) then re-run without final print)
        if(!val){
            printf("Try another interval? (y/n) ");
            scanf(" %c", &rr);
            if(rr != 'y'){
                break;
            }else{
                continue;
            }
        }
        //Final printing and rerun question
        printf("For equation = %s,\non interval [%lf, %lf] at tolerance: %lf\n",EQUATIONS[selec], a, b, tolerance);
        printf("Bisect returned: %.8lf\nAcuraccy: %.12lf\nGo again? (y/n)", val, accuracy);
        scanf(" %c", &rr);

        if(rr != 'y') break;
        system("cls");
    }
    return 0;
}
