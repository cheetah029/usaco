

#include <iostream>
#include <vector>

using namespace std;

int _myNum = 0;
vector<string> _resList;

void DisplayList(vector<string> theList) {
    string solo = "&";

    for (size_t i = 0; i < theList.size(); i++) {
        solo = theList[i];

        cout << solo << endl;
    }
}

void ParseIn() {
    cin >> _myNum;
}

void Core() {
    // Step 1: Create vector for 1 bit
    _resList.push_back("0");
    _resList.push_back("1");

    // Step 2: For n - 1 times, flip and add prefix
    int maxi = _resList.size();

    for (int i = 0; i < _myNum - 1; i++) {
        for (int j = 0; j < maxi; j++) {
            _resList.push_back("1" + _resList[maxi - 1 - j]);
        }

        for (int k = 0; k < maxi; k++) {
            _resList[k] = "0" + _resList[k];
        }

        maxi *= 2;
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