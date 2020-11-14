// file copying

/*********
 * read a charecter
 * while(chare is not EOF indicator)
 *      output the charecter just read
 *      read a character
 */
#include <stdio.h>

int main() {
    int c;
     

    while( (c = getchar()) != EOF) {
        //putchar prints the character usually on the screen
        putchar(c);
    }
    return 0;
}