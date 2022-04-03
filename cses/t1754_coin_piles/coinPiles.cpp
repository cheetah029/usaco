

#include <iostream>
#include <vector>

using namespace std;

struct Pair {
    int p1;
    int p2;
};

int _maxi = 0;
vector<Pair> _pairList;
vector<string> _resList;

void DisplayList(vector<string> theList) {
    string solo = "";

    for (int i = 0; i < theList.size(); i++) {
        solo = theList[i];

        cout << solo << endl;
    }
}

void ParseIn() {
    Pair curPair;

    cin >> _maxi;

    for (int i = 0; i < _maxi; i++) {
        cin >> curPair.p1 >> curPair.p2;
        _pairList.push_back(curPair);
    }
}

bool CanEmpty(int p1, int p2) {
    return ((p1 + p2) % 3 == 0) && (p1 / 2 <= p2) && (p2 / 2 <= p1);
}

void Core() {
    Pair solo;

    for (int i = 0; i < _pairList.size(); i++) {
        solo = _pairList[i];

        if (CanEmpty(solo.p1, solo.p2)) {
            _resList.push_back("YES");
        } else {
            _resList.push_back("NO");
        }
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