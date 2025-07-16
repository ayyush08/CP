#include<bits/stdc++.h>
using namespace std;

struct DSU
    {
        vector<int> parent;
        vector<int> rank;
        void init(int n)
        {
            parent.assign(n, 0);
            iota(parent.begin(), parent.end(), 0);
            rank.assign(n, 0);
        }
        int find(int v)
        {
            if (parent[v] == v)
                return v;
            return parent[v] = find(parent[v]);
        }
        void merge(int a, int b)
        {
            a = find(a);
            b = find(b);
            if (a != b)
            {
                if (rank[a] < rank[b])
                    swap(a, b);
                parent[b] = a;
                if (rank[a] == rank[b])
                    rank[a]++;
            }
        }
    };

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,m,k; cin >> n >> m >> k;

set<pair<int,int>> edges;
for(int i = 0; i < m; i++)
{
    int u, v; cin >> u >> v;
    u--; v--;
    if(u > v) swap(u, v); 
    edges.insert({u, v});
}

vector<pair<string,pair<int,int>>> ops;
set<pair<int,int>> cuttingEdges;


for(int i = 0; i < k; i++)
{
    string op; cin >> op;
    int u, v; cin >> u >> v;
    u--; v--;
    if(u > v) swap(u, v);
    ops.push_back({op, {u, v}});
    if(op=="cut") cuttingEdges.insert({u, v});
    
}

DSU dsu;
dsu.init(n);


for(auto &edge: edges){
    if(!cuttingEdges.count(edge)){
        dsu.merge(edge.first, edge.second);
    }
}


vector<string> ans;

for(int i=k-1;i>=0; i--)
{
    string op = ops[i].first;
    int u = ops[i].second.first;
    int v = ops[i].second.second;

    if(op=="ask"){
        if(dsu.find(u)==dsu.find(v)) ans.push_back("YES");
        else ans.push_back("NO");
    }
    if(op=="cut"){
        dsu.merge(u, v);
    }
}

reverse(ans.begin(), ans.end());

for(auto &s: ans){
    cout << s << "\n";
}

return 0;
}