
#include <stdio.h>

int main(){
	int input;
	long countTab = 0;
	long countBlank = 0;
	while( (input = getchar()) != EOF) {
		if(input == '\t')countTab++;
		if(input == ' ')countBlank++;
		if(input == '\n')printf(" tabs count  %6ld\n blanks count %6ld\n",countTab,countBlank);
		
	 
	}



}
