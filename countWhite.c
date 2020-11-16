#include <stdio.h>

int main(){
	int nWhite,nOther,i,input;
	int nDigit[10];
	for (i = 0; i<10; i++) {
		nDigit[i] = 0;
	}
	while((input = getchar()) != EOF) {
		if (input >='0' && input <= '9' )
			++nDigit[input - '0'];
		else if (input == ' ' || input == '\t' || input == '\n')
			++nWhite;
		else
			++nOther;
	
		

	}
		printf("\n digits equals");
		for(i = 0; i < 10; i++)
			printf(" %d ",nDigit[i]);
		printf("\n");





}
