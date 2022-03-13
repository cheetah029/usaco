

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> _numList;
int _amountOfNums = 0;

void DisplayList(vector<int> theList) {
    int solo = 0;

    for (int i = 0; i < theList.size(); i++) {
        solo = theList[i];

        cout << solo << ",";
    }

    cout << endl;
}

void ParseIn() {
    int curInt = 0;

    ifstream inFile("bubbleSort.in");

    inFile >> _amountOfNums;

    for (int i = 0; i < _amountOfNums; i++) {
        inFile >> curInt;
        _numList.push_back(curInt);
    }

    inFile.close();
}

void Core() {
    int temp = 0;

    for (int j = _amountOfNums - 1; j > 0; j--) {
        for (int i = 0; i < j; i++) {
            if (_numList[i] > _numList[i + 1]) {
                temp = _numList[i];
                _numList[i] = _numList[i + 1];
                _numList[i + 1] = temp;
            }
        }
    }
}

void CWriteOut() {
    DisplayList(_numList);
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}