#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 20;

vector<int> adj[MAXN];
int up[MAXN][LOG]; // up[v][j] = 2^j-th ancestor of v
int depth[MAXN];

void dfs(int v, int p)
{
    up[v][0] = p;
    for (int i = 1; i < LOG; ++i)
    {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (int u : adj[v])
    {
        if (u != p)
        {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v); // make u deeper

    // Bring u to same depth as v
    for (int i = LOG - 1; i >= 0; --i)
        if (depth[u] - (1 << i) >= depth[v]) // Check if we can lift u by 2^i
            u = up[u][i];

    if (u == v)
        return u; // u is ancestor of v

    // Lift both until parents match
    for (int i = LOG - 1; i >= 0; --i)
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }

    return up[u][0]; 
}

int distance(int u, int v)
{
    int ancestor = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[ancestor];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth[1] = 0; // root node depth

    dfs(1,1); // Start DFS from root node

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << distance(u, v) << '\n'; // Output the distance between u and v
    }

    return 0;
}