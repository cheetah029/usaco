

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _amountOfNums = 0;

vector<int> _numList;
vector<int> _resList;

void DisplayList(vector<int> theList) {
    int solo = 0;

    for (int i = 0; i < theList.size(); i++) {
        solo = theList[i];

        cout << solo << ",";
    }

    cout << endl;
}

void ParseIn() {
    int curNum = 0;

    ifstream inFile("multiThree.in");

    inFile >> _amountOfNums;

    for (int i = 0; i < _amountOfNums; i++) {
        inFile >> curNum;
        _numList.push_back(curNum);
    }

    inFile.close();

    // cout << "_amountOfNums->" << _amountOfNums << endl;

    // cout << "_numList.size->" << _numList.size() << endl;

    // DisplayList(_numList);
}

void Core() {
    int solo = 0;

    for (int i = 0; i < _numList.size(); i++) {
        solo = _numList[i];

        solo *= 3;

        _resList.push_back(solo);
    }
}

void CWriteOut() {
    DisplayList(_resList);
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}
