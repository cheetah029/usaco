

#include <iostream>
#include <vector>

using namespace std;

vector<int> _numList;
long long int _res = 0;

void ParseIn() {
    int maxi = 0;
    int curInt = 0;

    cin >> maxi;

    for (int i = 0; i < maxi; i++) {
        cin >> curInt;
        _numList.push_back(curInt);
    }
}

void Core() {
    long long int count = 0;

    for (int i = 1; i < _numList.size(); i++) {
        if (_numList[i - 1] > _numList[i]) {
            count += _numList[i - 1] - _numList[i];
            _numList[i] = _numList[i - 1];
        }
    }

    _res = count;
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