#include <iostream>

using namespace std;

int getSelection() {
    cout << "enter selsection" << endl;
    cout << "1 : searching" << endl;
    cout << "2 : view record" << endl;

    int input;
    cin >> input;
    return input;
}

void processSelection(int option) {
    switch(option) {
        case 1 :
        cout << "searching" << endl;
        break;
        case 2 :
        cout << "View record" << endl;
        break;
        default :
        cout << "unrecognised function" << endl;

    }


}

int main() {
    int selection;
    
    do {
        selection = getSelection(); 
        processSelection(selection);

    } while(selection<3);

   
    return 0;
}