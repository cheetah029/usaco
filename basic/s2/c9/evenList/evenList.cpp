

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> _myList;
vector<int> _evenList;

void DisplayList(vector<int> theList) {
    int solo = 0;

    for (int i = 0; i < theList.size(); i++) {
        solo = theList[i];

        cout << solo << " ";
    }

    cout << endl;
}

void ParseIn() {
    int curInt = 0;

    ifstream inFile("evenList.in");

    while (inFile >> curInt) {
        _myList.push_back(curInt);
    }

    inFile.close();
}

void Core() {
    int solo = 0;

    for (int i = 0; i < _myList.size(); i++) {
        solo = _myList[i];

        if (solo % 2 == 0) {
            _evenList.push_back(solo);
        }
    }
}

void CWriteOut() {
    cout << _evenList.size() << endl;

    DisplayList(_evenList);
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}