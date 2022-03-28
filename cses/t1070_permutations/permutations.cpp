

#include <iostream>

using namespace std;

int _maxi = 0;

void ParseIn() {
    cin >> _maxi;
}

void Core() {
    if (_maxi < 4 && _maxi != 1) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    for (int i = 2; i <= _maxi; i += 2) {
        cout << i << " ";
    }

    for (int i = 1; i <= _maxi; i += 2) {
        cout << i << " ";
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