#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b)
        { return a.second < b.second; });
    int movies = 0;
    int last_time = 0;

    for (int i = 0; i < n; i++)
    {
        if(v[i].first >= last_time){
            movies++;
            last_time=v[i].second;
        }
    }

    cout << movies;

    return 0;
}


//Start time sorted approach(unchecked)

// int last = -1;

// if(last == v[i][0]) last = min(last,v[i][1]);
// else{
// cnt++;
// last = v[i][1];
// }

