

#include <iostream>
#include <fstream>

using namespace std;

int _myArray[29];
int _maxi = 0;
int _res = 0;

void DisplayArray() {
    for (int i = 0; i < _maxi; i++) {
        cout << _myArray[i] << ",";
    }

    cout << endl;
}

void ParseIn() {
    int curInt = 0;

    ifstream inFile("arrayDef.in");

    inFile >> _maxi;

    for (int i = 0; i < _maxi; i++) {
        inFile >> curInt;
        _myArray[i] = curInt;
    }

    inFile.close();
}

void Core() {
    for (int i = 0; i < _maxi; i++) {
        _res += _myArray[i];
    }
}

void CWriteOut() {
    cout << _res << endl;
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}