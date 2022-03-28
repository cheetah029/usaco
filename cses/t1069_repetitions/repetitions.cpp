

#include <iostream>

using namespace std;

string _myStr = "Error";
int _res = 0;

void ParseIn() {
    cin >> _myStr;
}

void Core() {
    int count = 1;
    int maxCount = 1;

    for (int i = 1; i < _myStr.length(); i++) {
        if (_myStr[i] == _myStr[i - 1]) {
            count++;
            if (count > maxCount) {
                maxCount = count;
            }
        } else {
            count = 1;
        }
    }

    _res = maxCount;
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