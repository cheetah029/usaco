

#include <iostream>
#include <fstream>

using namespace std;

string _myStr = "";

void DisplayString(string theStr) {
    string backwardStr = "";

    for (int i = _myStr.length() - 1; i > -1; i--) {
        backwardStr += _myStr[i];
    }

    if (_myStr == backwardStr) {
        cout << "'" << _myStr << "'" << " is a palindrome." << endl;
    } else {
        cout << "'" << _myStr << "'" << " is not a palindrome." << endl;
    }
}

void ParseIn () {
    ifstream inFile("palindromeSimple.in");

    inFile >> _myStr;

    inFile.close();
}

int main () {
    ParseIn();

    DisplayString(_myStr);

    return 0;
}
