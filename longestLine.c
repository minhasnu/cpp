#include <stdio.h>
#define MAXLENGTH 1000


int getLine(char line[], int maxline);
void copy(char to[] ,char from[]);

int main(){
    
    char line[MAXLENGTH];
    char longestLine[MAXLENGTH];
    int maxLength,length;
    
    maxLength = 0;
    length = 0;
    
    // initialise a line length
     
    // get line and return its length
    // check if its line length
    while((length = getLine(line,MAXLENGTH))>0){
        if(length > maxLength){
            maxLength = length;
            copy(longestLine,line);

        } 
    }

    if(maxLength > 0)
        printf("%s",longestLine);
    
    printf("max length %d  ", maxLength);

}

int getLine(char line[], int lim) {
    int input;
    int length;
    length = 0;
    while((input = getchar()) != EOF && input != '.' && length < lim && input != '\n'){
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

void copy(char to[] ,char from[]){
   int i;
   i = 0;
   while((to[i] = from[i]) != '\0'){
       i++;
   }

}
    

    
