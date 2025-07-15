#include<bits/stdc++.h>
using namespace std;

#define int long long

int charToNode(char c, int n) {
    return n + (c - 'a');
}

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for(int neighbor : graph[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
    }

signed main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n; cin >> n;
vector<string> passwords(n);
for (int i = 0; i < n; ++i)  cin >> passwords[i];

vector<vector<int>> graph(n+26);

for(int i=0;i<n;i++){
    for(char c: passwords[i]) {
        graph[i].push_back(charToNode(c, n));
        graph[charToNode(c, n)].push_back(i);
    }
}

int components = 0;
vector<bool> visited(n + 26, false);
for(int i=0;i<n;i++){
    if(!visited[i]) {
        dfs(i, graph, visited);
        components++;
    }
}


cout << components << endl;
return 0;
}