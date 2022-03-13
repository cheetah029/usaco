

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _amountOfChars = 0;
int _starIndex = 0;
vector<char> _myList;
string _res = "";

void DisplayList(vector<char> theList) {
    char solo = 'E';

    for (int i = 0; i < theList.size(); i++) {
        solo = theList[i];

        cout << solo;
    }

    cout << endl;
}

void ParseIn() {
    ifstream inFile("drawStar.in");

    inFile >> _amountOfChars >> _starIndex;

    inFile.close();
}

void Core() {
    for (int i = 0; i < _amountOfChars; i++) {
        _myList.push_back('o');
    }

    _myList[_starIndex] = '*';
}

void CWriteOut() {
    DisplayList(_myList);
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}