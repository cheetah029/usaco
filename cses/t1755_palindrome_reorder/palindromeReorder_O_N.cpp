

#include <iostream>
#include <map>

using namespace std;

string _myStr = "&";
string _resStr = "NO SOLUTION";

void DisplayMap(map<char, int> theMap) {
    for (auto const& member: theMap) {
        cout << member.first << "->" << member.second << ", ";
    }
    cout << endl;
}

void ParseIn() {
    cin >> _myStr;
}

void Core() {
    int oddCount = 0;
    map<char, int> letterCounts;
    
    // 1. Count occurrence of each letter
    // bool repeated = false;
    // Letter curLetter;
    char solo;
    for (size_t i = 0; i < _myStr.length(); i++) {
        solo = _myStr[i];
        if (letterCounts.find(solo) == letterCounts.end()) {
            letterCounts[solo] = 1;
        } else {
            letterCounts[solo]++;
        }
    }

    /*
    m = {}
    m['a'] = 3
    solo = 'b'
    if solo not in m:
       m[solo] = 1
    else:
       m[solo] += 1
    */
    // DisplayMap(letterCounts);
    
    // 2. Figure out if a solution is possible and remember the odd letter

    char oddChar = '&';
    for (auto & letter : letterCounts) {
        if (letter.second % 2 != 0) {
            oddChar = letter.first;
            oddCount++;
            if (oddCount > 1) {
                return;
            }
        }
    }

    // 3. If a solution is possible

    // 3.1. Prepopulate result with all "&"s

    string ansStr(_myStr.length(), '&');
    // for (int i = 0; i < _myStr.length(); i++) {
    //     _resList.push_back("&");
    // }

    // 3.2. Put the odd letter in the middle if there is one
    if (oddCount == 1) {
        ansStr[ansStr.length() / 2] = oddChar;
        // _resList[_resList.size() / 2] = oddChar;
        letterCounts[oddChar]--;
        // cout << "[DBG] " << "letterCounts[" << oddChar <<"]-->" << letterCounts[oddChar] << endl;
    }
    // DisplayMap(letterCounts);

    // if (oddCount == 1) {
    //     _resList[_resList.size() / 2] = letters[oddIndex].name;
    //     letterCounts[oddChar]--;
    //     // }
    
    // if (oddCount == 1) {
    //     _resList[_resList.size() / 2] = letters[oddIndex].name;
    //     letters[oddIndex].count--;
    // }


    // 3.3. Fill the result with two pointers starting from the first index
    // and the last index and proceeding towards the middle
    int front = 0;
    int back = ansStr.length() - 1;
    // int front = 0;
    // int back = _resList.size() - 1;

    for (auto const& letter: letterCounts) {
        for (int m = 0; m < letter.second; m += 2) {
            ansStr[front] = letter.first;
            ansStr[back] = letter.first;

            front++;
            back--;
        }
    }
    // DisplayMap(letterCounts);

    // for (int k = 0; k < letters.size(); k++) {
    //     for (int m = 0; m < letters[k].count; m += 2) {
    //         _resList[front] = letters[k].name;
    //         _resList[back] = letters[k].name;

    //         front++;
    //         back--;
    //     }
    // }

    _resStr = ansStr;
}

void CWriteOut() {
    // DisplayList(_resList);
    cout << _resStr << endl;
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}