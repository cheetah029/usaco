

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Metal {
    string _name;
    int _volumePercentage;
    double _density;
};

vector<Metal> _myList;
double _totalMass = 0.0;
double _res = 0.0;

void ParseIn() {
    Metal curMetal;
    string trash = "";

    ifstream inFile("alloyDensity.in");

    inFile >> _totalMass;

    while (inFile >> curMetal._name >> curMetal._volumePercentage >> trash >> curMetal._density) {
        _myList.push_back(curMetal);
    }

    inFile.close();
}

void Core() {
    Metal solo;

    for (int i = 0; i < _myList.size(); i++) {
        solo = _myList[i];
        _res += solo._density * solo._volumePercentage / 100;
    }
}

void CWriteOut() {
    cout << _res << endl;
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}