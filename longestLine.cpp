#include <iostream>
#define MAXLENGTH 1000

using namespace std;

int main() {
    int max;
    int line[MAXLENGTH];
    max = 0;

    cout << getLine(max) << endl;
    return 0;
}

int getLine(int maximum) {
    int input;
    int lineLength;
    lineLength = 0;

    while((input = getchar()) != EOF ){
        
        maximum++;
        lineLength++;
        printf(" %d %d ",maximum,lineLength);
        if(input = '.'){
            if(lineLength > maximum) maximum = lineLength;
            lineLength = 0;

        }


    }
    

    return maximum;
}