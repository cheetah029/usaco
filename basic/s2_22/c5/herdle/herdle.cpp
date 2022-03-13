

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<char> _ans;
vector<char> _guess;
int _green = 0;
int _yellow = 0;

void DisplayList(vector<char> theList) {
    char solo = '&';

    for (int i = 0; i < theList.size(); i++) {
        solo = theList[i];

        cout << solo << ",";
    }

    cout << endl;
}

void ParseIn() {
    char curChar = 0;

    ifstream inFile("herdle.in");

    for (int i = 0; i < 9; i++) {
        inFile >> curChar;
        _ans.push_back(curChar);
    }

    for (int i = 0; i < 9; i++) {
        inFile >> curChar;
        _guess.push_back(curChar);
    }

    inFile.close();
}

void Core() {
    // Step 1: Count all the greens
    // "Remove" greens from BOTH _ans and _guess (change them to other chars)
    for (int i = 0; i < 9; i++) {
        if (_ans[i] == _guess[i]) {
            _ans[i] = '&';
            _guess[i] = '_';
            _green++;
        }
    }

    // Step 2: Count all the yellows
    // "Remove" yellows from BOTH _ans and _guess (change them to other chars)
    for (int i = 0; i < 9; i++) {
        for (int m = 0; m < 9; m++) {
            if (_ans[i] == _guess[m]) {
                _ans[i] = '&';
                _guess[m] = '_';
                _yellow++;
            }
        }
    }
}

void CWriteOut() {
    cout << _green << endl << _yellow << endl;
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}