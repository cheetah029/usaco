

#include <iostream>
#include <fstream>

using namespace std;

int _myNum = 0;

void ParseIn() {
    ifstream inFile("monkLoop.in");
    inFile >> _myNum;
    inFile.close();
}

void Core(int myInt) {
    if (myInt == 1) {
        cout << "0:M->T->Monk->Story;" << endl;
        return;
    }

    Core(myInt - 1);

    cout << myInt - 1 << ":What->M->T->Monk->Story;" << endl;
}

int main() {
    ParseIn();
    Core(_myNum);

    return 0;
}