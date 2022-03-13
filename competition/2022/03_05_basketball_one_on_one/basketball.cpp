

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string _myStr = "";
string _res = "";

void ParseIn() {
    ifstream inFile("basketball.in");

    inFile >> _myStr;

    inFile.close();
}

void Core() {
    vector<string> myList;
    string curStr = "";
    int aP = 0;
    int bP = 0;
    int endP = 0;

    for (int i = 0; i < _myStr.length(); i++) {
        if (i % 2 == 0) {
            curStr = _myStr[i];
        } else {
            curStr += _myStr[i];
            myList.push_back(curStr);
        }
    }

    for (int i = 0; i < myList.size(); i++) {
        if (myList[i][0] == 'A') {
            aP += myList[i][1] - '0';
        } else {
            bP += myList[i][1] - '0';
        }
    }

    endP = aP - bP;

    if (endP > 0) {
        _res = "A";
    } else {
        _res = "B";
    }
}

void Core2() {
    _res = _myStr[_myStr.size() - 2];
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