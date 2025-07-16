#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P pair<int, int>


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<P>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }


    priority_queue<P, vector<P>, greater<P>> pq;
    vector<int> visited(n, 0);
    pq.push({0, 0});
    int s = 0;
    while (!pq.empty())
    {
        auto [weight, node] = pq.top();
        pq.pop();

        if (visited[node])
            continue;
        visited[node] = 1;
        s += weight;
        for (auto [adjNode, edgeWt] : adj[node])
        {
            if (!visited[adjNode])
                pq.push({edgeWt, adjNode});
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    cout << s;

    return 0;
}