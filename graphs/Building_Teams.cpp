#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> color;
vector<int> parent;
int cycle_start, cycle_end;

bool isCycle(int start)
{
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        for (auto it : adj[currentNode])
        {
            if (color[it] == -1)
            {
                color[it] = !color[currentNode];
                q.push(it);
            }
            else if (color[it] == color[currentNode])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    color.assign(n, -1);
    vector<int> ans(n, 1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!isCycle(i))
            {
                cout << "IMPOSSIBLE" << '\n';
                return 0;
            }
        }

    }
    for (int i = 0; i < n; i++){
        cout << color[i] + 1 << ' ';
    }
        return 0;
}