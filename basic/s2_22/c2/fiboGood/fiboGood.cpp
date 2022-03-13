

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _fiboIndex = 0;
int _res = 0;
int _count = 0;

void ParseIn() {
    ifstream inFile("fiboGood.in");
    inFile >> _fiboIndex;
    inFile.close();
}

void DisplayList(vector<long long> theList) {
    long long solo = 0;
    for (int i = 0; i < theList.size(); i++) {
        solo = theList[i];
        cout << solo << ",";
    }
    cout << endl;
}

int FiboGood(int fiboIndex) {
    // cout << "fiboIndex->" << fiboIndex;
    // cout << " count->" << _count++ << endl;

    vector<long long> myList{0, 1, 1}; // [1, 1, 2, 3, 5, 8, ...]
    long long a = 0, b = 0;
    // myList.push_back(1);
    // myList.push_back(1);

    for (int i = 3; i < fiboIndex + 1; i++) {
        a = myList[i - 2];
        b = myList[i - 1];
        myList.push_back(a + b);
        DisplayList(myList);
        // FiboGood(i - 1) + FiboGood(i - 2);
    }

    return myList[fiboIndex];
}

void Core() {
    for (int i = 1; i < _fiboIndex + 1; i++) {
        _res = FiboGood(i);
        cout << "fibo(" << i << ")->" << _res << endl;
    }
}

void CWriteOut() {
    // cout << _res << endl;
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}