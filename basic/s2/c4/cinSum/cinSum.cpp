

#include <iostream>
#include <fstream>

using namespace std;

int res = 0;

int main () {

    int _maxi = 0;
    int curInt = 0;
    int localSum = 0;

    cout << "How many numbers?" << endl;
    cin >> _maxi;
    cout << endl;

    for (int i = 0; i < _maxi; i++) {
        cout << "Enter a number: ";
        cin >> curInt;

        localSum += curInt;

        // debug:
        // cout << "curInt->" << curInt;
        // cout << "; ";
        // cout << "localSum->" << localSum;
        // cout << endl;
        cout << endl;
    }

    res = localSum;
    cout << "The sum of the numbers is " << localSum << "." << endl << endl;

    return 0;
}
