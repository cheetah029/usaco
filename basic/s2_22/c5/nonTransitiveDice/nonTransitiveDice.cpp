

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _amountOfTests = 0;
vector<vector<int> > _dice;

void DisplayList(vector<vector<int> > theList) {
    int solo = 0;

    for (int i = 0; i < theList.size(); i++) {
        for (int m = 0; m < theList[i].size(); m++) {
            solo = theList[i][m];
            cout << solo << ",";
        }

        cout << endl;
    }
}

void ParseIn() {
    int solo = 0;

    ifstream inFile("nonTransitiveDice.in");

    inFile >> _amountOfTests;

    for (int i = 0; i < _amountOfTests; i++) {
        vector<int> row;

        for (int m = 0; m < 8; m++) {
            inFile >> solo;
            row.push_back(solo);
        }

        _dice.push_back(row);
    }

    inFile.close();
}

void Core() {
    ;
}

void CWriteOut() {
    DisplayList(_dice);
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}