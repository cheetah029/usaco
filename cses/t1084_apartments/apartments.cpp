

#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> _people;
priority_queue<int> _houses;
int _tolerance;
int _res;

void ParseIn() {
    int nPeople = 0;
    int nHouses = 0;
    int solo = 0;

    cin >> nPeople >> nHouses >> _tolerance;

    for (int i = 0; i < nPeople; i++) {
        cin >> solo;
        _people.push(-solo);
    }

    for (int i = 0; i < nHouses; i++) {
        cin >> solo;
        _houses.push(-solo);
    }
}

void Core() {
    int person = 0;
    int house = 0;
    int ans = 0;

    while (!_people.empty() && !_houses.empty()) {
        person = -_people.top();
        house = -_houses.top();

        if (person - _tolerance <= house && house <= person + _tolerance) {
            // person likes house, skip both person and house
            ans++;
            _people.pop();
            _houses.pop();
        } else if (person > house) { 
            // house is too small, skip house
            _houses.pop();
        } else {
            // skip person
            _people.pop();
        }
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