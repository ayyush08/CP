#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool isCycle(int v){
    color[v]='r'; //red(visited)
    for(int child: adj[v]){
        if(color[child]=='w'){ //uncolored or white
            parent[child]=v; //mark parent
            if(isCycle(child)) return true; //recur for child to find cycle
        }else if(color[child]=='r'){ //if child is red (Already visited)
            cycle_end = v;
            cycle_start = child;
            return true; //cycle found
        }
    }
    color[v]='b'; //mark as processed path (black)
    return false; //no cycle found in this path
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
cin >> n >> m;
adj.resize(n);
for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--; v--; 
    adj[u].push_back(v); //directed graph
}
color.assign(n,'w');
parent.assign(n, -1);
cycle_start = -1;
for(int v=0;v<n;v++){
    if(color[v]=='w' && isCycle(v)) break;
}

if(cycle_start==-1){
    cout << "IMPOSSIBLE" << '\n';
}else{
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for(int v = cycle_end; v != cycle_start; v = parent[v]){
        cycle.push_back(v);
    }
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end()); //reverse to get correct order
    cout << cycle.size() << '\n';
    for(int v : cycle){
        cout << v + 1 << ' ';
    }
}
return 0;
}