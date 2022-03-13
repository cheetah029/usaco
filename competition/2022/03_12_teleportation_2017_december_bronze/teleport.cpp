

#include <iostream>
#include <fstream>

using namespace std;

int _start_385683258 = 0;
int _end_74574336 = 0;
int _t1_45346346 = 0;
int _t2_35234545 = 0;
int _res_29384732 = 0;

void ParseIn() {
    ifstream inFile("teleport.in");

    inFile >> _start_385683258 >> _end_74574336 >> _t1_45346346 >> _t2_35234545;

    inFile.close();
}

void Core () {
    int ans1 = abs(_end_74574336 - _start_385683258);
    int ans2 = abs(_t1_45346346 - _start_385683258) + abs(_end_74574336 - _t2_35234545);
    int ans3 = abs(_t2_35234545 - _start_385683258) + abs(_end_74574336 - _t1_45346346);

    _res_29384732 = ans1;

    if (ans2 < _res_29384732) {
        _res_29384732 = ans2;
    }

    if (ans3 < _res_29384732) {
        _res_29384732 = ans3;
    }
}

void CWriteOut() {
    ofstream outFile("teleport.out");

    outFile << _res_29384732 << endl;

    outFile.close();
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}