#include <bits/stdc++.h>
using namespace std;

bool canMake(vector<int> &students,int k,int councils){
    int cnt = 0;
    for(int student:students){
        cnt+=min(cnt,councils);
    }

    return cnt >= k;

}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> students(n);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> students[i];
        if (students[i] > mx)
            mx = students[i];
    }
    int ans=0;

    int low = 0, high = 1e9;

    while (low<=high)
    {
        int mid = (low + high) / 2;
        if (canMake(students, k, mid))
        {
            ans=mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

    cout << ans ;
    return 0;
}

//If there are enough students available to make L councicls consisting of k studetns each then f(l)=1