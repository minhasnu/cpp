#include <stdio.h>


int main() {
    int input, i, nwhite, other;
    int ndigit[10];
    nwhite = other = 0;
    for(i = 0; i < 10; i++){
        ndigit[i] = 0;
    }
    while((input = getchar()) != EOF){
        if(input > '0' && input <= '9'){
            ++ndigit[input - '0'];
        } else if (input == ' '){
            ++nwhite;
        } else  {
            ++other;
        }
        
    }
    printf("digits = ");
    for(i = 0; i < 10; i++){
        printf(" %d",ndigit[i]); 
    }
    printf("\nwhitespace = %d",nwhite);
    printf(" other = %d \n", other);
    return 0;

}