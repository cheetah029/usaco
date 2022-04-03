

#include <iostream>

using namespace std;

int _myNum = 0;
int _res = 0;

void ParseIn() {
    cin >> _myNum;
}

void Core() {
    int num = _myNum;
    int ans = 0;

    while (num > 0) {
        ans += num / 5;
        num /= 5;
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