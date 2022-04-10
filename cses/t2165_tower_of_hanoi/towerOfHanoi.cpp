

#include <iostream>

using namespace std;

int _myInt = 0;

void ParseIn() {
    cin >> _myInt;
}

int CountMovesRecursion(int numOfDisks) {
    if (numOfDisks == 1) {
        return 1;
    }

    return CountMovesRecursion(numOfDisks - 1) * 2 + 1;
}

int CountMoves(int numOfDisks) {
    int power = 1;

    for (int i = 0; i < numOfDisks; i++) {
        power <<= 1;
    }

    return power - 1;
}

void Move(int numOfDisks, char source, char buffer, char target) {
    if (numOfDisks == 1) {
        cout << source << " " << target << endl;
        return;
    }

    Move(numOfDisks - 1, source, target, buffer);
    cout << source << " " << target << endl;
    Move(numOfDisks - 1, buffer, source, target);
}

void Core() {
    char left = '1';
    char mid = left + 1;
    char right = left + 2;

    cout << CountMoves(_myInt) << endl;
    Move(_myInt, left, mid, right);
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