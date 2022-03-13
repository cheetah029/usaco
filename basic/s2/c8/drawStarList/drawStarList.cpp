

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _amountOfChars = 0;
int _amountOfStars = 0;
vector<int> _starIndices;
vector<char> _charList;

void ParseIn() {
    int curIndex = 0;
    ifstream inFile("drawStarList.in");
    inFile >> _amountOfChars >> _amountOfStars;

    for (int i = 0; i < _amountOfStars; i++) {
        inFile >> curIndex;
        _starIndices.push_back(curIndex);
    }

    inFile.close();
}

void Core() {
    int curIndex = 0;

    for (int i = 0; i < _amountOfChars; i++) {
        _charList.push_back('o');
    }

    for (int i = 0; i < _starIndices.size(); i++) {
        curIndex = _starIndices[i];
        _charList[curIndex] = '*';
    }
}

void CWriteOut() {
    char solo = '&';

    // Start of the ruler
    for (int i = 0; i < _charList.size(); i++) {
        cout << i % 10;
    }

    cout << endl;
    // End of the ruler

    for (int i = 0; i < _charList.size(); i++) {
        solo = _charList[i];

        cout << solo;
    }

    cout << endl;
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}