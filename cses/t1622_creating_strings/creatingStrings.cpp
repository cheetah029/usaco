

#include <iostream>
#include <algorithm>

using namespace std;

string _myStr = "Error";

void ParseIn() {
    cin >> _myStr;
}

string NextPermutation(string s) {
    int right = s.length() - 1;
    int left = right - 1;
    char temp = '&';

    // From right to left, find the first decreasing letter
    // That is the target to swap
    while (left > -1 && s[left] >= s[right]) {
        left--;
        right--;
    }

    if (left < 0) {
        return "";
    }

    // From right to left, find the first letter greater than the target
    // Then swap the them
    temp = s[left];

    for (int i = s.length() - 1; i > -1; i--) {
        if (s[i] > temp) {
            s[left] = s[i];
            s[i] = temp;
            break;
        }
    }

    // Reverse the substring on the right of the target
    left++;
    right = s.length() - 1;

    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }

    return s;
}

void Core() {
    string s = _myStr;
    string sortedS = "Error";
    int count = 1;

    // Sort the string
    sort(s.begin(), s.end());
    sortedS = s;

    // Count the permutations and print the count
    while ((s = NextPermutation(s)) != "") {
        count++;
    }

    cout << count << endl;

    // Print all of the permutations of the string lexicographically
    cout << sortedS << endl;

    while ((sortedS = NextPermutation(sortedS)) != "") {
        cout << sortedS << endl;
    }
}

void CWriteOut() {
    // Output is in Core
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}