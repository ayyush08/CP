#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> topoSort(int numCourses)
{
    queue<int> q;
    vector<int> ans;
    vector<int> inDegree(numCourses, 0);
    for(auto & edge : adj)
    {
        for(auto& neighbor : edge)
        {
            inDegree[neighbor]++;
        }
    }
    for (int i = 0; i < numCourses; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int front = q.front();
        ans.push_back(front);
        q.pop();
        for (auto it : adj[front])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
                q.push(it);
        }
    }
    return ans;
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
    }

    vector<int> ans = topoSort(n);
    if (ans.size() != n)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i : ans)
    {
        cout << i + 1 << " ";
    }

    return 0;
}