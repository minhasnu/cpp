#include <stdio.h>
#define MAXLENGTH 1000


int getLine();
void copy();

int main(){
    
    extern char line[MAXLENGTH];
    extern char longestLine[MAXLENGTH];
    int maxLength,length;
    
    maxLength = 0;
    length = 0;
    
    // initialise a line length
     
    // get line and return its length
    // check if its line length
    while((length = getLine())>0){
        if(length > maxLength){
            maxLength = length;
            copy();
        } 
    }

    if(maxLength > 0)
        printf("\n %s",longestLine);
    
    printf("max length %d  ", maxLength);

}

int getLine() {
    extern char line[];
    int input;
    int length;
    length = 0;

    while((input = getchar()) != EOF && input != '.' && length < MAXLENGTH && input != '\n'){
        line[length] = input;
        length++;      
    }
    if(input == '\n'){
        line[length] = input;
        length++;
    }
    line[length]='\0';
    

    return length;
}

void copy(){
    extern char line[];
    extern char longestLine[];
    int i;
    i = 0;
    while((longestLine[i] = line[i]) != '\0'){
       i++;
    }

}
    

    
