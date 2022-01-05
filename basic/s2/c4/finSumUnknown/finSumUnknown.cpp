

#include <iostream>
#include <fstream>

using namespace std;

int res = 0;

void ParseIn() {
    int curInt = 0;
    int localSum = 0;
    int count = 0;

    ifstream inFile("finSumUnknown.in");

    while (inFile >> curInt) {
        count++;
        localSum += curInt;

        cout << "curInt->" << curInt;
        cout << "; ";
        cout << "localSum->" << localSum;
        cout << endl;
    }

    inFile.close();

    res = localSum;
    cout << endl << "The sum of the " << count << " numbers is " << localSum << "." << endl << endl;
}

int main () {
    ParseIn();

    return 0;
}
