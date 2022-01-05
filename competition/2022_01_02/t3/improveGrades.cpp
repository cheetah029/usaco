

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> scores;

    int amountOfScores = 0;
    int curScore = 0;
    int averageScore = 0;
    int numOfRetests = 0;

    cin >> amountOfScores;

    for (int i = 0; i < amountOfScores; i++) {
        cin >> curScore;
        scores.push_back(curScore);
    }

    while (averageScore < 90) {
        int minScore = 100;
        int sumOfScores = 0;

        for (int i = 0; i < scores.size(); i++) {
            if (scores[i] < minScore) {
                minScore = scores[i];
            }

            sumOfScores += scores[i];

            scores[i] = 100;
        }

        averageScore = (sumOfScores) / (scores.size() - 2);

        numOfRetests++;
    }

    return 0;
}
