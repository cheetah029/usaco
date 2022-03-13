

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> _myList;
int _res = 0;

void ParseIn() {
    int amountOfNums = 0;
    int curInt = 0;

    ifstream inFile("ccNegative.in");

    inFile >> amountOfNums;

    for (int i = 0; i < amountOfNums; i++) {
        inFile >> curInt;
        _myList.push_back(curInt);
    }

    inFile.close();
}

void Core() {
    for (int i = 0; i < _myList.size(); i++) {
        if (_myList[i] < 0) {
            _res++;
        }
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