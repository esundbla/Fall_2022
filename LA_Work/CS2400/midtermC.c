#include <stdio.h>  //C library for input output


int main(){         // Main text of program
    int x, y, z;    
    x=1;            //$s1 = 1
    y=0;            //$s2 = 0
    z=7;            //$s3 = 7

    if( z*y < x){               
        printf("Less than");     //Syscall
    }else
        printf("greater than");  //Syscall 
    return 0;                    //Exit Syscall
}