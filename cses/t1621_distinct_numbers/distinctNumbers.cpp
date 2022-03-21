

#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> _numSet;
int _res = 0;

void ParseIn() {
    int maxi = 0;
    int curInt = 0;

    cin >> maxi;

    for (int i = 0; i < maxi; i++) {
        cin >> curInt;
        _numSet.insert(curInt);
    }
}

void Core() {
    _res = _numSet.size();
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