

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int _nTickets = 0;
int _mCustomers = 0;
vector<int> _ticketPrices;
vector<int> _offerPrices;
vector<int> _resList;

void DisplayList(vector<int> theList) {
    int solo = 0;

    for (size_t i = 0; i < theList.size(); i++) {
        solo = theList[i];

        cout << solo << endl;
    }
}

void ParseIn() {
    int solo = 0;

    cin >> _nTickets >> _mCustomers;

    for (int i = 0; i < _nTickets; i++) {
        cin >> solo;
        _ticketPrices.push_back(solo);
    }

    for (int i = 0; i < _mCustomers; i++) {
        cin >> solo;
        _offerPrices.push_back(solo);
    }
}

void Core() {
    int solo = 0;
    vector<int>::iterator it;

    // Step 1: Sort the ticket prices.
    sort(_ticketPrices.begin(), _ticketPrices.end());

    // Step 2: For each offer price, find the highest affordable ticket price.
    for (size_t i = 0; i < _offerPrices.size(); i++) {
        if (_ticketPrices.size() == 0) {
            _resList.push_back(-1);
            continue;
        }

        solo = _offerPrices[i];
        it = lower_bound(_ticketPrices.begin(), _ticketPrices.end(), solo);

        if (it == _ticketPrices.end()) {
            _resList.push_back(*(it - 1));
            _ticketPrices.erase(it - 1);
            continue;
        }

        if (*it == solo) {
            _resList.push_back(solo);
            _ticketPrices.erase(it);
            continue;
        }

        if (it == _ticketPrices.begin()) {
            _resList.push_back(-1);
            continue;
        }

        _resList.push_back(*(it - 1));
        _ticketPrices.erase(it - 1);
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