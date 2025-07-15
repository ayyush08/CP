#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
vector<int> sum(MAXN, 0);

void dfs(int node){
    for(int child : graph[node]) {
        dfs(child);
        sum[node] += 1 + sum[child];
    }
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int employees; cin >> employees;
graph->resize(employees + 1);
sum.resize(employees, 0);
for(int i=2;i<=employees;i++){
    int boss; cin >> boss;
    graph[boss].push_back(i);
}

dfs(1);
for(int i=1;i<=employees;i++){
    cout << sum[i] << " ";
}



return 0;
}