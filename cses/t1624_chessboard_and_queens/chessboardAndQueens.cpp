

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N_ROWS = 8;      // number of rows on the board
int N_COLS = N_ROWS; // number of columns on the board
char BLOCKER = '*';
set<pair<int, int> > _blockerSet;
vector<vector<int> > _ansList;
int _res = -1;

void DisplayList(vector<int> theList) {
    int solo = 0;

    for (size_t i = 0; i < theList.size(); i++) {
        solo = theList[i];

        cout << solo << " ";
    }

    cout << endl;
}

void DisplayBlockers(set<pair<int, int> > blockers) {
    set<pair<int, int> >::iterator it;

    for (it = blockers.begin(); it != blockers.end(); it++) {
        cout << (*it).first << "," << (*it).second << endl;
    }
}

void ParseIn() {
    char curSquare = '&';

    for (int i = 0; i < N_ROWS; i++) {
        for (int j = 0; j < N_COLS; j++) {
            cin >> curSquare;
            // cout << curSquare; // DBG only

            if (BLOCKER == curSquare) {
                _blockerSet.insert(make_pair(i, j));
            }
        }
        // cout << endl; // DBG only
    }
    // DisplayBlockers(_blockerSet); // DBG only
}

bool QueensAreAttacking(vector<int> board) {
    int row = board.size() - 1;
    int col = board[row];
    int curRow = 0;
    int curCol = 0;

    for (size_t i = 0; i < board.size() - 1; i++) {
        curRow = i;
        curCol = board[i];

        if (col == curCol ||                // same column attack
            row + col == curRow + curCol || // same slash attack
            row - col == curRow - curCol)   // same backslash attack
        {
            return true;
        }
    }

    return false;
}

bool QueenIsBlocked(int row, int col) {
    set<pair<int, int> >::iterator it;

    for (it = _blockerSet.begin(); it != _blockerSet.end(); it++) {
        if ((*it).first == row && (*it).second == col) {
            return true;
        }
    }

    return false;
}

bool BoardIsValid(vector<int> board) {
    if (board.size() == 0) {
        return true;
    }

    if (QueensAreAttacking(board)) {
        return false;
    }

    if (QueenIsBlocked(board.size() - 1, board[board.size() - 1])) {
        return false;
    }

    return true;
}

void NQueens(int N, vector<int> ans) {
    if (!BoardIsValid(ans)) {
        return;
    }

    if (ans.size() == N) {
        _ansList.push_back(ans);
        return;
    }

    for (int i = 0; i < N_COLS; i++) {
        ans.push_back(i);
        NQueens(N, ans);
        ans.pop_back();
    }
}

void Core() {
    vector<int> ans;
    NQueens(N_ROWS, ans);
    _res = _ansList.size();
}

void CWriteOut() {
    for (size_t i = 0; i < _ansList.size(); i++) {
        // DisplayList(_ansList[i]); // DBG only
    }

    cout << _res << endl;
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}