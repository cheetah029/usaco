

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _myNum = 0;

void DisplayInt(int theInt) {
    vector<int> digitList;
    vector<int> backwardDigitList;

    int theNum = theInt;

    while (theNum > 0) {
        digitList.push_back(theNum % 10);
        theNum /= 10;
    }

    for (int i = digitList.size() - 1; i > -1; i--) {
        backwardDigitList.push_back(digitList[i]);
    }

    if (digitList == backwardDigitList) {
        cout << theInt << " is a palindrome." << endl;
    } else {
        cout << theInt << " is not a palindrome." << endl;
    }
}

void ParseIn() {
    ifstream inFile("palindromeInteger.in");

    inFile >> _myNum;

    inFile.close();
}


int main () {
    ParseIn();

    for (int i = 0; i < 1001; i++) {
        DisplayInt(_myNum + i);
    }

    return 0;
}