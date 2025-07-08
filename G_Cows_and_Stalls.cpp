#include<bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& location, int pos,int cows){
    int placedCows=1;
    int last = location[0];
    for(int i=1;i<location.size();i++){
        if(last-location[i]>=pos){
            placedCows++;
            last=location[i];
        }
        if(placedCows>=cows) return true;
    }
    return false;
}

int main()
{
int tc; cin >> tc;
while(tc--)
{
    int n,c; cin >> n >> c;
    vector<int>location(n);
    for(int i=0;i<n;i++) cin >> location[i];
    sort(location.begin(),location.end());
    int l = 1,r=location[n-1]-location[0];
    while (l<=r)
    {
        int mid = (l+r)/2;
        if(canPlace(location,mid,c)){
            
            l=mid+1;
        }else r=mid-1;
    }
    
    cout << r << endl;

}
return 0;
}

