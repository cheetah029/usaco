

#include <iostream>

using namespace std;

int _numOne = 0;
int _numTwo = 0;

int main () {

    cout << "Give me 2 numbers: " << endl;
    cin >> _numOne;
    cin >> _numTwo;

    if (_numOne > _numTwo) {
        cout << _numOne;
        cout << endl;

        return 0;
    }

    cout << _numTwo << endl;


    return 0;
}
