#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
    float c,f;
    
    printf("conversion chart from farenheit to celsius \n ");
    for(int i = LOWER; i <= UPPER; i+=STEP) {
        f = i;
        c = 5.0 * (f - 32) /9.0;
       
        printf(" %3.0f  %9.2f\n",f,c);
    }
}