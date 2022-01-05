

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> _myList;

void DisplayList () {
    int solo = 0;

    for (int i = 0; i < _myList.size(); i++) {
        solo = _myList[i];

        cout << solo << ",";
    }

    cout << endl;
}

void ParseIn() {
    int curInt = 0;

    ifstream inFile("vectorDef.in");

    while(inFile >> curInt) {
        _myList.push_back(curInt);
    }

    inFile.close();

    cout << "size->" << _myList.size() << endl;

    DisplayList();
}

int main () {
    ParseIn();

    return 0;
}
