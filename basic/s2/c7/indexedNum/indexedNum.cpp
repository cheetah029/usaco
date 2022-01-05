

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _amountOfNums = 0;
string _theIndex = "";
vector<int> _numList;
int _res = 0;

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

    ifstream inFile("indexedNum.in");

    inFile >> _amountOfNums >> _theIndex;

    for (int i = 0; i < _amountOfNums; i++) {
        inFile >> curNum;
        _numList.push_back(curNum);
    }

    inFile.close();

    // cout << "_amountOfNums->" << _amountOfNums << endl;

    // cout << "_numList.size->" << _numList.size() << endl;

    // DisplayList(_numList);

    // cout << "the index->" << _theIndex << endl;
}

void Core() {
    int myIndex = 0;
    myIndex = stoi(_theIndex);
    _res = _numList[myIndex];
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
