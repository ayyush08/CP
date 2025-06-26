#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int>cards(n);
    for(int i=0;i<n;i++) cin >> cards[i];   
    int low = 0,high=n-1;
    bool turn = true;
    int sereja=0,dima=0;
    while(low<=high){
        int card = max(cards[low],cards[high]);
        if(turn){
            sereja+=card;
            if(card == cards[low]) low++;
            else high--;
            turn=false;
        }else{
            dima+=card;
            if(card == cards[low]) low++;
            else high--;
            turn = true;
        }
    }
    cout << sereja << " " << dima;
    return 0;
}