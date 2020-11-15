#include <stdio.h>

int main() {
    int input;
    long lineCount = 0;
    while( (input=getchar()) != EOF ) {
	if(input == '\n') {
	    lineCount++;
	    printf("%6ld\n",lineCount);
	}

    }

}
