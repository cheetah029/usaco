

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string _myStr = "Error";
int _numOfVowels = 0;

void DisplayStr(string theStr) {
    char solo = '&';

    for (int i = 0; i < theStr.length(); i++) {
        solo = theStr[i];

        cout << solo << ",";
    }

    cout << endl;
}

void ParseIn() {
    ifstream inFile("ccVowel.in");

    inFile >> _myStr;

    inFile.close();
}

void Core() {
    char solo = '&';

    for (int i = 0; i < _myStr.length(); i++) {
        solo = _myStr[i];

        if (solo == 'a') {
            _numOfVowels++;
        } else if (solo == 'e') {
            _numOfVowels++;
        } else if (solo == 'i') {
            _numOfVowels++;
        } else if (solo == 'o') {
            _numOfVowels++;
        } else if (solo == 'u') {
            _numOfVowels++;
        }
    }
}

void CWriteOut() {
    cout << _numOfVowels << endl;
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}