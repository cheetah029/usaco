

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

string _inFileName = "smallestNum.in";
vector<int> _myNums;
int _res = INT_MAX;

void CWriteOut() {
    cout << _res << endl;
}

void Core() {
    int curNum = 0;

    for (int i = 0; i < 9; i++) {
        curNum = _myNums[i];

        if (curNum < _res) {
            _res = curNum;
        }
    }
}

void ParseIn() {
    int curNum = 0;

    ifstream inFile(_inFileName);

    for (int i = 0; i < 9; i++) {
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
