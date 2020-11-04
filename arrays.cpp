#include <iostream>
using namespace std;

int main() { 
    int value[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int column = sizeof(value[0])/sizeof(int);
    int row = sizeof(value)/sizeof(value[0]);

    cout << " number of rows " <<row << endl;
    cout << " number of column " << column << endl;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << " " << value[i][j] << flush;
        }
        cout << endl;
    }


}