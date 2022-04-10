

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int _maxi = 0;
long long int _res = 0;
vector<int> _weightList;

void DisplayList(vector<int> theList) {
    int solo = 0;

    for (size_t i = 0; i < theList.size(); i++) {
        solo = theList[i];

        cout << solo << ",";
    }

    cout << endl;
}

void ParseIn() {
    int curWeight = 0;

    cin >> _maxi;

    for (int i = 0; i < _maxi; i++) {
        cin >> curWeight;
        _weightList.push_back(curWeight);
    }
}

void MinDiff(vector<int> weights, long long int weightA, long long int weightB, long long int* res) {
    int curWeight = 0;
    long long int diff = 0;

    if (weights.size() == 0) {
        diff = abs(weightA - weightB);

        if (*res > diff) {
            *res = diff;
        }

        return;
    }

    curWeight = weights[weights.size() - 1];
    weights.pop_back();
    MinDiff(weights, weightA + curWeight, weightB, res);
    MinDiff(weights, weightA, weightB + curWeight, res);
}

void Core() {
    // Brute force all of the possibilities
    // Calculate the minimum difference
    long long int ans = INT64_MAX;
    MinDiff(_weightList, 0, 0, &ans);
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