

#include <iostream>
#include <vector>

using namespace std;

struct Coord {
    int row;
    int column;
};

vector<Coord> _coords;
vector<long long int> _resList;

void DisplayCoords(vector<Coord> theList) {
    Coord solo;

    for (int i = 0; i < theList.size(); i++) {
        solo = theList[i];

        cout << solo.row << "," << solo.column << endl;
    }
}

void DisplayList(vector<long long int> theList) {
    long long int solo = 0;

    for (int i = 0; i < theList.size(); i++) {
        solo = theList[i];

        cout << solo << endl;
    }
}

void ParseIn() {
    int maxi = 0;
    int row = 0;
    int column = 0;
    Coord curCoord;

    cin >> maxi;

    for (int i = 0; i < maxi; i++) {
        cin >> row >> column;
        curCoord.row = row;
        curCoord.column = column;
        _coords.push_back(curCoord);
    }
}

long long int LookUp(int row, int column) {
    long long int greater = 0;
    long long int ans = 1;

    if (row > column) {
        greater = row;
    } else {
        greater = column;
    }

    ans = greater * (greater - 1) + 1;

    if (greater % 2 == 0) {
        ans += row - column;
    } else {
        ans += column - row;
    }

    return ans;
}

void Core() {
    int row = 0;
    int column = 0;
    long long int ans = 0;

    for (int i = 0; i < _coords.size(); i++) {
        row = _coords[i].row;
        column = _coords[i].column;
        ans = LookUp(row, column);
        _resList.push_back(ans);
    }
}

void CWriteOut() {
    DisplayList(_resList);
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}