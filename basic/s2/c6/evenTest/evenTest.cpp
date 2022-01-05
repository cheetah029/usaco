

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> _myNums;

int _amountOfEvenNums = 0;

void CWriteOut() {
    cout << _amountOfEvenNums << endl;
}

void Core() {
    for (int i = 0; i < 3; i++) {
        if (_myNums[i] % 2 == 0) {
            _amountOfEvenNums++;
        }
    }
}

void ParseIn() {
    int curNum = 0;

    ifstream inFile("evenTest.in");

    for (int i = 0; i < 3; i++) {
        inFile >> curNum;
        _myNums.push_back(curNum);
    }

    inFile.close();
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}