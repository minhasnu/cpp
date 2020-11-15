#include <stdio.h>

int main() {
    long c,count;
    count = 0;
    
    while((c = getchar())!=EOF ){
	
	count++;
	printf("%ld \n",count*sizeof(c));

    }
}

