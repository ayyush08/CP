#include <bits/stdc++.h>
using namespace std;
#define int long long

bool canMake(vector<int> &students,int k,int councils){
    int cnt = 0;
    for(int student:students){
        cnt+=min(student,councils);
    }

    return cnt >= (k*councils);

}

signed main()
{
    int n, k;
    cin >> k >> n;
    vector<int> students(n);
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> students[i];
        tot+=students[i];
    }
    int ans=0;

    int low = 0, high = tot/k;

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