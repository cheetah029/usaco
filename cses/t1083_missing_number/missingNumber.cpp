

#include <iostream>
#include <vector>

using namespace std;

vector<int> _missingList;
int _res = 0;

void DisplayList(vector<int> theList) {
    int solo = 0;

    for (int i = 0; i < theList.size(); i++) {
        solo = theList[i];

        cout << solo << ",";
    }

    cout << endl;
}

void ParseIn() {
    int maxi = 0;
    int curInt = 0;

    cin >> maxi;

    for (int i = 0; i < maxi - 1; i++) {
        cin >> curInt;
        _missingList.push_back(curInt);
    }
}

void Core() {
    int ans = 0;
    int solo = 0;

    for (int i = 0; i < _missingList.size(); i++) {
        solo = _missingList[i];
        ans ^= solo;
        ans ^= i + 1;
    }

    ans ^= _missingList.size() + 1;
    _res = ans;
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