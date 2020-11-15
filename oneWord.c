#include <stdio.h>
#define IN 1
#define OUT 0
int main() {
	int input,state;

	while((input = getchar()) != EOF) {
		if(input == ' '|| input == '\t' || input == '\n'){
                	state = OUT;	    
		} else if(state == OUT) {
		
			state = IN;
			printf("\n\n");	
		}
		if(state == IN)printf("%c",input);
	}


}
