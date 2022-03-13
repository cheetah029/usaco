

#include <iostream>
#include <fstream>

using namespace std;

void ParseIn() {
    // Input is in Core
}

long long int Hailstone(long long int myInt) {
    if (myInt % 2 == 0) {
        return myInt / 2;
    }

    return myInt * 3 + 1;
}

void Core() {
    long long int myInt = 0;

    cin >> myInt;

    while (myInt != 1) {
        cout << myInt << " ";
        myInt = Hailstone(myInt);
    }

    cout << myInt << endl;
}

void CWriteOut() {
    // Output is in Core
}

int main() {
    ParseIn();
    Core();
    // CWriteOut();

    return 0;
}