

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Score {
    int myScore;
    int fullScore;
};

vector<Score> _scoreList;
int _maxScore = 0;
int _totalScore = 0;

void DisplayList(vector<Score> theList) {
    Score solo;

    for (int i = 0; i < theList.size(); i++) {
        solo = theList[i];

        cout << solo.myScore << '/' << solo.fullScore << ",";
    }

    cout << endl;
}

void ParseIn() {
    Score curScore;
    char trash = '&';

    ifstream inFile("calcScore.in");

    inFile >> _maxScore;

    for (int i = 0; i < 3; i++) {
        inFile >> curScore.myScore;
        inFile >> trash;
        inFile >> curScore.fullScore;
        _scoreList.push_back(curScore);
    }

    inFile.close();

    DisplayList(_scoreList);
}

void Core() {
    Score solo;

    for (int i = 0; i < 3; i++) {
        solo = _scoreList[i];
        _totalScore += _maxScore * solo.myScore / 3 / solo.fullScore;
    }
}

void CWriteOut() {
    cout << _totalScore << endl;
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}