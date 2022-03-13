

#include <iostream>
#include <fstream>

using namespace std;

int _fiboIndex = 0;
int _res = 0;
int _count = 0;

void ParseIn() {
    ifstream inFile("fiboEvil.in");
    inFile >> _fiboIndex;
    inFile.close();
}

int FiboGood(int fiboIndex) {
    // cout << "fiboIndex->" << fiboIndex;
    // cout << " count->" << _count++ << endl;

    if (fiboIndex < 3) {
        return 1;
    }

    return FiboGood(fiboIndex - 1) + FiboGood(fiboIndex - 2);
}

void Core() {
    _res = FiboGood(_fiboIndex);
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