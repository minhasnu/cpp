#include <stdio.h>                                       

#define IN 1
#define OUT 0

int main() {
    int i, j, state, input, nHist[10],wordCount,wordLength;
    wordCount = wordLength = 0;
    
    for (i=0; i<10 ; i++)
        nHist[i] = 0;
    state = OUT;
    
    while((input = getchar()) != EOF){
        if(input == ' ' || input == '\n' || input == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
        }                
        if (state == IN){
            wordLength++;
        } else {
            if(wordLength!=0)
            nHist[wordLength]++;
            wordLength = 0;
        }
        

    }
    for(i=1; i < 10; i++)
    printf(" %d",nHist[i]);
    printf("\n");
    for (i = 0; i < 10; i++) {
        printf("%d ",i);
            for (j = 0; j < nHist[i]; j++ ){
                printf("-");
            }
        printf("\n");
    }



}



