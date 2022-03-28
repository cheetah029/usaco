

#include <iostream>
#include <vector>

using namespace std;

int _myInt = 0;

void ParseIn() {
    cin >> _myInt;
}

void Core() {
    if (_myInt % 4 == 1 || _myInt % 4 == 2) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    if (_myInt % 4 == 3) {
        // First Set
        cout << (_myInt + 1) / 2 << endl;
        cout << "1 2 ";

        for (int i = 4; i < _myInt; i += 4) {
            cout << i << " " << i + 3 << " ";
        }

        cout << endl;

        // Second Set
        cout << (_myInt - 1) / 2 << endl;
        cout << "3 ";

        for (int i = 4; i < _myInt; i += 4) {
            cout << i + 1 << " " << i + 2 << " ";
        }

        cout << endl;

        return;
    }

    // First Set
    cout << _myInt / 2 << endl;

    for (int i = 1; i < _myInt; i += 4) {
        cout << i << " " << i + 3 << " ";
    }

    cout << endl;

    // Second Set
    cout << _myInt / 2 << endl;

    for (int i = 1; i < _myInt; i += 4) {
        cout << i + 1 << " " << i + 2 << " ";
    }

    cout << endl;
}

void CWriteOut() {
    // Output is in Core
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}