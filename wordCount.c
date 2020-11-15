#include <stdio.h>
#include <stdbool.h>
int main() {
	int input,count,prevInput;
	bool secondValue = false;
	count = 0;
	while((input = getchar()) != EOF){
		//enter the loop if  its the second value
		if(secondValue){
		//if prev input is blank and the current input is not a blank tab or blank
			if(prevInput == ' '){
				if(input!=' '||input!='\t'||input!='\n') {
					count++;
					printf(" %10d\n",count);					
				}
			}
		}
		secondValue = true;
		prevInput =  input;

	}



}
