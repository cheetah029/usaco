

#include <iostream>

using namespace std;

int _myInt = 0;
int _res = 0;

void ParseIn() {
    cin >> _myInt;
}

void Core() {
    int ans = 1;

    for (int i = 0; i < _myInt; i++) {
        ans = (ans * 2) % 1000000007;
    }

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