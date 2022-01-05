

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

string _inFileName = "twoGs.in";
vector<int> _myNums;
vector<int> _res = {INT_MIN, INT_MIN};

void CWriteOut() {
    cout << _res[1] << " " << _res[0] << endl;
}

void Core() {
    int curNum = 0;

    for (int i = 0; i < 9; i++) {
        curNum = _myNums[i];

        if (curNum > _res[1]) {
            _res[0] = _res[1];
            _res[1] = curNum;
        } else if (curNum > _res[0]) {
            _res[0] = curNum;
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
