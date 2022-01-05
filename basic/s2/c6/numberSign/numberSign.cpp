

#include <iostream>

using namespace std;

int main () {
    int num = 0;

    cin >> num;

    if (num < 0) {
        cout << "-" << endl;
        return 0;
    }

    cout << "+" << endl;

    return 0;
}
