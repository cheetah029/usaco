

#include <iostream>
#include <vector>

using namespace std;

int _sideLength = 0;
vector<long long int> _resList;

void DisplayList(vector<long long int> theList) {
    long long int solo = 0;

    for (int i = 0; i < theList.size(); i++) {
        solo = theList[i];

        cout << solo << endl;
    }
}

void ParseIn() {
    cin >> _sideLength;
}

void Core() {
    long long int ans = 0;

    for (long long int i = 1; i < _sideLength + 1; i++) {
        ans = (i * i) * (i * i - 1) / 2 - (i - 1) * (i - 2) * 4;
        _resList.push_back(ans);
    }
}

void CWriteOut() {
    DisplayList(_resList);
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}