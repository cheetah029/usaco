

#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long int _MAX_PILLAR = 1000000000000000000L;
vector<long long int> _pillarList;
vector<long long int> _indices;
vector<long long int> _resList;

void DisplayList(vector<long long int> theList) {
    long long int solo = 0;

    for (size_t i = 0; i < theList.size(); i++) {
        solo = theList[i];

        cout << solo << endl;
    }
}

void ParseIn() {
    int maxi = 0;
    long long int curIndex = 0;

    cin >> maxi;
    // cout << "DBG " << "maxi->" << maxi << endl;

    for (int i = 0; i < maxi; i++) {
        cin >> curIndex;
        _indices.push_back(curIndex);
    }
}

long long int GetPillar(int numOfDigits) {
    long long int power = 1;
    long long int ones = 0;

    for (int i = 0; i < numOfDigits - 1; i++) {
        power *= 10;
        ones = ones * 10 + 1;
    }

    return power * (numOfDigits - 1) - ones + 1;
}

void BuildPillarList() {
    int numOfDigits = 0;
    long long int curPillar = 0;
    
    curPillar = GetPillar(numOfDigits);
    while (curPillar < _MAX_PILLAR) {
        _pillarList.push_back(curPillar);
        numOfDigits++;
        curPillar = GetPillar(numOfDigits);
    }
    _pillarList.push_back(curPillar);
}

int GetNumOfDigits(long long int k) {
    for (size_t i = 0; i < _pillarList.size(); i++) {
        if (k < _pillarList[i]) {
            return i - 1;
        }
    }
    return _pillarList.size();
}

long long int FindX(int nDigits, long long int k) {
    if (nDigits == 1) {
        return k;
    }

    long long int power = 1;

    for (int i = 0; i < nDigits - 1; i++) {
        power *= 10;
    }

    return power + (k - _pillarList[nDigits]) / nDigits;
}

int FindPositionInX(long long int x, long long int k, int nDigits) {
    int position = (k - _pillarList[nDigits]) % nDigits;
    return position;
}

void Core() {
    long long int k = -1;
    int numOfDigits = -1;
    long long int x = -1;
    int position = -1;

    // Suppose natural number x contains the kth digit in the infinite string.
    
    // Step 1: Make a pillar table for digit of x to the range of k.
    BuildPillarList();
    // DisplayList(_pillarList); // DBG only


    for (size_t i = 0; i < _indices.size(); i++) {
        k = _indices[i];
        // cout << "DBG " << "k->" << k << endl;

        // Step 2: Find the nDigits number for k.
        numOfDigits = GetNumOfDigits(k);
        // cout << "DBG " << "numOfDigits->" << numOfDigits << endl;

        // Step 3: According to the nDigits formula, find x for k.
        x = FindX(numOfDigits, k);
        // cout << "DBG " << "x->" << x << endl;

        // Step 4: According to the position formula, find the right position in x.
        position = FindPositionInX(x, k, numOfDigits);
        // cout << "DBG " << "position->" << position << endl;

        // Step 5: Save the answer in _resList.
        _resList.push_back(to_string(x)[position] - '0');
    }
}

void CWriteOut() {
    DisplayList(_resList);
}

int main() {
    // freopen("digitQueries.in", "r", stdin); // DBG: for USACO only 

    ParseIn();
    Core();
    CWriteOut();

    return 0;
}