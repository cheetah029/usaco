

#include <iostream>
#include <fstream>

using namespace std;

int _num = 0;

void TellStory (int cc) {
  
  cout << cc << ':';
  
  if (cc == 0) {
    cout << "M->T->Monk->Story;" << endl;
    // cc++;
    return TellStory(cc + 1);
  }

  cout << "What->M->T->Monk->Story;" << endl;

  if (cc == _num - 1) {
    return;
  }

  TellStory(cc + 1);

}

void ParseIn () {

  ifstream inFile("recursiveMonk.in");

  inFile >> _num;

  inFile.close();

}

void Core () {

  //nothing

}

void CWriteOut () {

  TellStory(0);

}

int main () {

  ParseIn();
  Core();
  CWriteOut();
  
  return 0;
}

