

#include <iostream>
#include <vector>

using namespace std;

constexpr size_t GRID_SIZE = 7;
string _pathString = "&";
vector<string> _paths;
int _res = 0;
bool _visited[GRID_SIZE + 2][GRID_SIZE + 2];

void ParseIn() {
    cin >> _pathString;
}

void DFS(int x, int y, string curPath) {
    // cout << "DBG " << "x->" << x << ", y->" << y 
    //     << ", p->" << curPath 
    //     << ", Number of paths->" << _paths.size()
    //     << endl;

    if (_visited[x][y]) {  // the current space must have not been visited
        return;
    }

    // Optimization 3
    if ((_visited[x][y-1] && _visited[x][y+1])
        && (!_visited[x-1][y] && !_visited[x+1][y])) {
        return;
    }

    if ((_visited[x-1][y] && _visited[x+1][y])
        && (!_visited[x][y-1] && !_visited[x][y+1])) {
        return;
    }


    // The path has to match the specified pattern
    char expected = _pathString[curPath.size() - 1];
    char curCh = curPath[curPath.size() - 1];
    pair<int, int> curPair;

    if (expected != curCh && expected != '?') {
        return;
    }

    // The target square has been reached
    if (x == 1 && y == GRID_SIZE) {
        if (curPath.length() == GRID_SIZE * GRID_SIZE - 1) {
            _paths.push_back(curPath);

            // cout << "DBG " << "x->" << x << ", y->" << y 
            //     << ", p->" << curPath 
            //     << ", Number of paths->" << _paths.size()
            //     << endl;
        }

        return;
    }

    // Optimization 4
    if (_visited[x-1][y-1] && _visited[x+1][y-1] && !_visited[x][y-1]) {
        _visited[x][y] = 1;
        DFS(x, y - 1, curPath + 'U');
        _visited[x][y] = 0;
        return;
    }

    if (_visited[x-1][y+1] && _visited[x+1][y+1] && !_visited[x][y+1]) {
        _visited[x][y] = 1;
        DFS(x, y + 1, curPath + 'D');
        _visited[x][y] = 0;
        return;
    }

    if (_visited[x-1][y-1] && _visited[x-1][y+1] && !_visited[x-1][y]) {
        _visited[x][y] = 1;
        DFS(x - 1, y, curPath + 'L');
        _visited[x][y] = 0;
        return;
    }

    if (_visited[x+1][y-1] && _visited[x+1][y+1] && !_visited[x+1][y]) {
        _visited[x][y] = 1;
        DFS(x + 1, y, curPath + 'R');
        _visited[x][y] = 0;
        return;
    }
    // End of Optimization 4

    char dirsCh[4] = {'U', 'D', 'L', 'R'};
    pair<int, int> dirs[4] = {make_pair(0, -1), make_pair(0, 1),
                              make_pair(-1, 0), make_pair(1, 0)};

    for (int i = 0; i < 4; i++) {
        _visited[x][y] = 1;

        curCh = dirsCh[i];
        curPair = dirs[i];

        DFS(x + curPair.first, y + curPair.second, curPath + curCh);

        _visited[x][y] = 0;
    }
}

int CountMatchingPaths() {
    return _paths.size();
}

void Core() {
    for (int i = 0; i < GRID_SIZE + 2; i++) {
        _visited[i][0] = 1;
        _visited[0][i] = 1;
        _visited[i][GRID_SIZE + 1] = 1;
        _visited[GRID_SIZE + 1][i] = 1;
    }

    DFS(1, 1, "");
    _res = CountMatchingPaths();
}

void CWriteOut() {
    cout << _res << endl;
}

int main() {
    // freopen("gridPaths.in", "r", stdin);

    ParseIn();
    Core();
    CWriteOut();

    return 0;
}