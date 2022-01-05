

#include <iostream>
#include <fstream>

using namespace std;

int _maxi = 0;
int res = 0;

// what: parse the following
// 5
// 1 10 20 5 6
void ParseIn() {
    int curInt = 0;
    int localMaxi = -1;

    ifstream inFile("finGreater.in");

    inFile >> _maxi;

    cout << "_maxi->" << _maxi << endl;

    for (int i = 0; i < _maxi; i++) {
        inFile >> curInt;

        // 1st iteration, 1 will be the winner
        if (curInt > localMaxi) {
            localMaxi = curInt;
        }

        cout << "curInt->" << curInt;
        cout << "; ";
        cout << "localMaxi->" << localMaxi;
        cout << endl;
    }

    inFile.close();

    res = localMaxi;
    cout << endl << "The greatest number is " << res << "." << endl << endl;
}

int main () {

    ParseIn();

    return 0;
}
