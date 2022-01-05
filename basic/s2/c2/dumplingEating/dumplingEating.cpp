

#include <iostream>

using namespace std;

int main () {

    int numOfDumplings = 0;
    int dumplingsEaten = 0;

    cout << endl << "How many dumplings?" << endl;
    cin >> numOfDumplings;

    if (numOfDumplings == 1) {
        cout << endl << "There is 1 dumpling." << endl << endl;
    } else {
        cout << endl << "There are " << numOfDumplings << " dumplings." << endl << endl;
    }

    for (int i = 0; i < numOfDumplings; i++) {
        dumplingsEaten++;

        if (dumplingsEaten == 1) {
            cout << "I ate 1 dumpling." << endl;
        } else {
            cout << "I ate " << dumplingsEaten << " dumplings." << endl;
        }

        if (numOfDumplings - dumplingsEaten == 1) {
            cout << "There is 1 dumpling left." << endl << endl;
        } else {
            cout << "There are " << numOfDumplings - dumplingsEaten << " dumplings left." << endl << endl;
        }
    }

    cout << "That's enough dumplings for today!" << endl << endl;

    return 0;
}
