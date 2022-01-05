

#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int theInt) {

  if (theInt < 0) {
    return false;
  }

  vector<int> digitList;
  vector<int> backwardDigitList;

  while (theInt > 0) {
    digitList.push_back(theInt % 10);
    theInt /= 10;
  }

  for (int i = digitList.size() - 1; i > -1; i --) {
    backwardDigitList.push_back(digitList[i]);
  }

  return digitList == backwardDigitList;
}

int main() {
  int num = 0;
  cin >> num;

  if (isPalindrome(num)) {
    cout << "Palindromic Number" << endl;
    return 0;
  }

  cout << "Non-Palindromic Number" << endl;

  return 0;
}
