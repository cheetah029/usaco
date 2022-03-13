

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> _checkList;
vector<int> _virusList;
vector<string> _res;

void DisplayList(vector<string> theList) {
    string solo = "";

    for (int i = 0; i < theList.size(); i++) {
        solo = theList[i];

        cout << solo << endl;
    }
}

void ParseIn() {
    int lenCheckList = 0;
    int lenVirusList = 0;
    int curInt = 0;

    ifstream inFile("virusCheck.in");

    inFile >> lenCheckList;

    for (int i = 0; i < lenCheckList; i++) {
        inFile >> curInt;
        _checkList.push_back(curInt);
    }

    inFile >> lenVirusList;

    for (int i = 0; i < lenVirusList; i++) {
        inFile >> curInt;
        _virusList.push_back(curInt);
    }

    inFile.close();
}

bool CheckItemIsVirus(int item) {
    int virus = 0;

    for (int i = 0; i < _virusList.size(); i++) {
        virus = _virusList[i];

        if (item == virus) {
            return true;
        }
    }

    return false;
}

void Core() {
    int item = 0;

    for (int i = 0; i < _checkList.size(); i++) {
        item = _checkList[i];

        if (CheckItemIsVirus(item)) {
            _res.push_back("Alert");
        } else {
            _res.push_back("Safe");
        }
    }
}

void CWriteOut() {
    DisplayList(_res);
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}