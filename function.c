#include <stdio.h>
#define IN 1
#define OUT 0
int power(int m, int n);


int main() {
    int input,first,m,n;
    first = IN;
    m = n = 0;
    

    while ((input = getchar()) != EOF){
        if(first == IN && input >= '0'&& input <= '9'){
            m = input - '0';
            printf("\n %d",m);
            first = OUT;
            
        } else if(first == OUT && input >= '0'&& input <= '9') {
            n = input - '0';
            printf("^%d = %d \n", n, power(m, n));
            first = IN;
        }

    }
   

}

int power(int m, int n ){
    int i,product;
    product = 1;
    for(i = 0; i < n; i++){
        product = product * m;  
    }
    return product;
    }