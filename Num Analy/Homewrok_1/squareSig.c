/*
 Square Significance
 Program demonstrating the substracting close values issue 
 Erik Sundblad
 9/1/2022
 */

#include <stdio.h>
#include <math.h>

int main(){
    double c = 246886422468;    
    double d = 13579;

    double orig = sqrt((c*c)+d)-c;      /* Original Formula with bad result */
    double cong = d/(sqrt((c*c)+d)+c);  /* Improved formula by conjugate multiplication*/

    printf("Original calculation yeilds %.16lf\n", orig );
    printf("Congugate equivilant = %.16lf\n", cong);

    return ;
}