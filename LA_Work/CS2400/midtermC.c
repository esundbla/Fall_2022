#include <stdio.h>

/*
int main(){
    int x, y, z;
    x=1;
    y=0;
    z=7;

    if( z*y < x){
        print("Less than");
    }else
        print("greater than");
    return 0;
}
*/
void main(){
    int x, e;                                       //Two variables to hold input $s0, $s1
    
    printf("Input the value of the base: ");        //Ask for user input
    scanf("%d", &x);                                //Store input into x

    printf("Input the value of the exponent: ");    //Ask for user input
    scanf("%d", &e);                                //Store input into e

    int i  = 1;                                     //Counter variable initialized to 1 
    for(i;i<e;i++){                                 //loop wile 1 < e
        e = e*e;                                    //opperation
    }

    printf("The final result is: %d", e);            //Output the results

}