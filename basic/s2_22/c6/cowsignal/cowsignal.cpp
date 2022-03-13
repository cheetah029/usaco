

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _tall = 0;
int _wide = 0;
int _enlarger = 0;
vector<vector<char> > _smallSheet;
vector<vector<char> > _bigSheet;

void DisplayList(vector<vector<char> > theList) {
    ofstream outFile("cowsignal.out");

    char solo = '&';
    vector<char> soloList;

    for (int i = 0; i < theList.size(); i++) {
        soloList = theList[i];

        for (int m = 0; m < soloList.size(); m++) {
            solo = soloList[m];

            outFile << solo;
        }

        outFile << endl;
    }

    outFile.close();
}

void ParseIn() {
    char solo = '&';

    ifstream inFile("cowsignal.in");

    inFile >> _tall >> _wide >> _enlarger;

    for (int i = 0; i < _tall; i++) {
        vector<char> curRow;

        for (int m = 0; m < _wide; m++) {
            inFile >> solo;
            curRow.push_back(solo);
        }

        _smallSheet.push_back(curRow);
    }

    inFile.close();

    DisplayList(_smallSheet);
}

void Core() {
    vector<char> curSmallRow;

    for (int i = 0; i < _smallSheet.size(); i++) {
        vector<char> curBigRow;

        curSmallRow = _smallSheet[i];

        for (int m = 0; m < curSmallRow.size(); m++) {
            for (int a = 0; a < _enlarger; a++) {
                curBigRow.push_back(curSmallRow[m]);
            }
        }

        for (int b = 0; b < _enlarger; b++) {
            _bigSheet.push_back(curBigRow);
        }
    }
}

void CWriteOut() {
    DisplayList(_bigSheet);
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}