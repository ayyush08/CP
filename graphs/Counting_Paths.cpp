#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 20;

vector<int> adj[MAXN];
int up[MAXN][LOG], depth[MAXN];
int diff[MAXN], res[MAXN];
int n, m;

// Binary lifting: Preprocess parents and depth
void dfs(int v, int p)
{
    up[v][0] = p;
    for (int i = 1; i < LOG; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];

    for (int u : adj[v])
    {
        if (u != p)
        {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}

// Get LCA of a and b
int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    for (int i = LOG - 1; i >= 0; --i)
    {
        if (depth[a] - (1 << i) >= depth[b]) // Lift a up to the same depth as b
            a = up[a][i];
    }
    if (a == b)
        return a;

    for (int i = LOG - 1; i >= 0; --i)
    {
        if (up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}


// Post-order DFS that propagates the path counts upward.
// Each node adds its children’s counts to its own diff[v].

int dfs2(int v, int p)
{
    int total = diff[v];
    for (int u : adj[v])
    {
        if (u != p)
        {
            total += dfs2(u, v);
        }
    }
    res[v] = total;
    return total;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;


    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Preprocessing for LCA
    dfs(1, 1); // Assume root is 1

    // Process paths
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        int anc = lca(a, b);

        // Difference array updates
        diff[a] += 1;
        diff[b] += 1;
        diff[anc] -= 1;
        if (up[anc][0] != anc) // lca is not root
            diff[up[anc][0]] -= 1;
    }

    // Accumulate path counts
    dfs2(1, 1); // Assume root is 1

    // Output result
    for (int i = 1; i <= n; ++i)
    {
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}
