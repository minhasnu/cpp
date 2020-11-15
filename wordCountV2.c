#include <stdio.h>
#define IN 1 	/*in a word*/
#define OUT 0

int main() {
    int input,wordCount,state;
    wordCount = 0;
    state = OUT;
    while((input = getchar())!= EOF) {
	if(input == ' '|| input == '\t' || input == '\n') {
	     state = OUT;
	} else {
	    if (state == OUT){
	    wordCount++;
	    state = IN;
	    printf("%6d\n",wordCount);
	    }
        }
    }


}
