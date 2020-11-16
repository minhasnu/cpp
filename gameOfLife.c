#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
int main() {

    int i,j,input,state[SIZE][SIZE], xloc,yloc,innerI,innerJ,population;
    int populationIndex[SIZE][SIZE];

    population = xloc = yloc =  i = j = 0;
    //initialising all states to zero
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            state[j][i] = 0;
        }
    }
    //getting input
    while((input = getchar()) != EOF ){
        system("clear");
        //check for existance
        /*****/
        // the population computatiom starts when g is pressed
        if(input == 'g') {
            for(i = 0; i < SIZE; i++){
                for(j = 0; j < SIZE; j++){
                    for(innerI = -1; innerI <= 1; innerI++ ) {
                        for(innerJ = -1; innerJ <= 1; innerJ++){
                            if(state[i+innerI][j+innerJ] == 1 && !(innerJ==0 && innerI == 0) )      
                                population++;
                                
                        }
                    }
                    populationIndex[i][j] = population;
                    population = 0;
                        
                }
            }
            for(i = 0; i < SIZE; i++ ){
                for(j = 0; j < SIZE; j++){
                    if (populationIndex[i][j] > 3) {
                        state[i][j] = 0;
                    } else if (populationIndex[i][j] == 3){
                        state[i][j] = 1;
                    } else if(populationIndex[i][j] == 0 || populationIndex[i][j] == 1) {
                        state[i][j] = 0;
                    } 

                }
            }
   
        }
        

        for(i = 0; i < SIZE; i++){
            for(j = 0; j < SIZE; j++){
                if(j == xloc && i == yloc || state[i][j] == 1){            
                    printf(" o");
                } else  printf(" -");         
            }
            printf("\n");
        }   
        printf("\n");
        if(input == 'd')
            xloc++; 
        else if (input == 'w')
            yloc--;
        else if (input == 'a')
            xloc--;
        else if(input == 's')
            yloc++;
        else if(input == 'j'){
            state[yloc][xloc] = 1;

        }
    }
    
}
