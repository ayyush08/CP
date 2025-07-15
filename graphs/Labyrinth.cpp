#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int m, int n) {
    return (i >= 0 && j >= 0 && i < m && j < n);
}


bool bfs(pair<int,int> start, pair<int,int> end,
         vector<vector<char>>& grid,
         string &desc, int &length) {

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> visited(m, vector<int>(n, 0));
    vector<vector<pair<int,int>>> parent(m, vector<pair<int,int>>(n, {-1, -1}));

    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = 1;

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<char> dirChar = {'U', 'D', 'L', 'R'};

    bool found = false;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (make_pair(x, y) == end) {
            found = true;
            break;
        }

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (isValid(nx, ny, m, n) &&
                !visited[nx][ny] &&
                (grid[nx][ny] == '.' || grid[nx][ny] == 'B')) {
                visited[nx][ny] = 1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    if (!visited[end.first][end.second]) {
        return false;
    }

    string path;
    pair<int,int> cur = end;
    while (cur != start) {
        pair<int,int> prev = parent[cur.first][cur.second];

        if (prev.first == cur.first - 1 && prev.second == cur.second) path += 'D';
        else if (prev.first == cur.first + 1 && prev.second == cur.second) path += 'U';
        else if (prev.first == cur.first && prev.second == cur.second - 1) path += 'R';
        else if (prev.first == cur.first && prev.second == cur.second + 1) path += 'L';

        cur = prev;
    }

    reverse(path.begin(), path.end());
    desc = path;
    length = path.size();
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    pair<int,int> start, end;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    string desc;
    int length = 0;

    if (bfs(start, end, grid, desc, length)) {
        cout << "YES\n" << length << "\n" << desc << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
