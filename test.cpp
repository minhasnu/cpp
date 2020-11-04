#include <iostream>

using namespace std;

int main() {
    cout << "enter selsection" << endl;

    cout << "1 : searching" << endl;
    cout << "2 : view record" << endl;

    int input;
    cin >> input;

    if (input ==1) {
        cout << "searching..." << endl;
    }

    switch(input) {
        case 1 :
        cout << "searching" << endl;
        break;
        case 2 :
        cout << "View record" << endl;
        break;
        case default :
        cout << "unrecognised function" << endl;
        break;

    }
    return 0;
}