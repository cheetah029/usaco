

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> _scores;
vector<int> _weightsOfScores = {20, 30, 50};

int _res = 0;

void CWriteOut() {
    cout << _res << endl;
}

void Core() {
    for (int i = 0; i < 3; i++) {
        _res += _scores[i] * _weightsOfScores[i] / 100;
    }
}

void ParseIn() {
    int curScore = 0;

    ifstream inFile("score.in");

    for (int i = 0; i < 3; i++) {
        inFile >> curScore;
        _scores.push_back(curScore);
    }

    inFile.close();
}

void CParseIn() {
    int curScore = 0;

    for (int i = 0; i < 3; i++) {
        cin >> curScore;
        _scores.push_back(curScore);
    }
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}
