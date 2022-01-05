

#include <iostream>

using namespace std;

int main () {

// int foodCc = 0;

//     //console-out
// cout << "Hello, World." << endl;
// cout << "I eat chicken." << endl;

// foodCc = foodCc + 1;

// cout << "I eat pizza." << endl;
// foodCc = foodCc + 1;

// cout << "Food I ate->" << foodCc << endl;

    int squareSide = 0;
    int res = 0;

    while (true) {

        cout << "Give a number as side:" << endl;

        cin >> squareSide;

        res = squareSide * squareSide;

        cout << "Area of square with " << squareSide << " is->" << res << endl;

    }



    return 0;
}

