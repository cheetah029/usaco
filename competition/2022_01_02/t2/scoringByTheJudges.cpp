

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    vector<int> scores;

    int amountOfScores = 0;
    int curScore = 0;
    int maxScore = 0;
    int minScore = 20000;
    int sumOfScores = 0;
    float averageScore = 0;

    cin >> amountOfScores;

    for (int i = 0; i < amountOfScores; i++) {
        cin >> curScore;
        scores.push_back(curScore);
    }

    for (int i = 0; i < scores.size(); i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
        }

        if (scores[i] < minScore) {
            minScore = scores[i];
        }

        sumOfScores += scores[i];
    }

    averageScore = (sumOfScores - maxScore - minScore) * 1.0 / (scores.size() - 2);

    cout << fixed;
    cout << setprecision(2);
    cout << averageScore << endl;

    return 0;
}
