

#include <iostream>
#include <vector>

using namespace std;

struct Letter {
    int count;
    char name;
};

string _myStr = "&";
vector<string> _resList;

void DisplayList(vector<string> theList) {
    string solo = "&";

    for (int i = 0; i < theList.size(); i++) {
        solo = theList[i];

        cout << solo;
    }

    cout << endl;
}

void ParseIn() {
    cin >> _myStr;
}

void Core() {
    vector<Letter> letters;
    int oddIndex = 0;
    int oddCount = 0;

    // 1. Count occurrence of each letter
    bool repeated = false;
    Letter curLetter;

    for (int i = 0; i < _myStr.length(); i++) {
        repeated = false;
        curLetter.name = _myStr[i];
        curLetter.count = 1;

        for (int j = 0; j < letters.size(); j++) {
            if (curLetter.name == letters[j].name) {
                repeated = true;
                letters[j].count++;
                break;
            }
        }

        if (repeated == false) {
            letters.push_back(curLetter);
        }
    }

    // 2. Figure out if a solution is possible and remember the odd letter
    for (int i = 0; i < letters.size(); i++) {
        if (letters[i].count % 2 != 0) {
            oddIndex = i;
            oddCount++;
            if (oddCount > 1) {
                _resList.push_back("NO SOLUTION");
                return;
            }
        }
    }

    // 3. If a solution is possible

    // 3.1. Prepopulate result with all "&"s
    for (int i = 0; i < _myStr.length(); i++) {
        _resList.push_back("&");
    }

    // 3.2. Put the odd letter in the middle if there is one
    if (oddCount == 1) {
        _resList[_resList.size() / 2] = letters[oddIndex].name;
        letters[oddIndex].count--;
    }

    // 3.3. Fill the result with two pointers starting from the first index
    // and the last index and proceeding towards the middle
    int front = 0;
    int back = _resList.size() - 1;

    for (int k = 0; k < letters.size(); k++) {
        for (int m = 0; m < letters[k].count; m += 2) {
            _resList[front] = letters[k].name;
            _resList[back] = letters[k].name;

            front++;
            back--;
        }
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