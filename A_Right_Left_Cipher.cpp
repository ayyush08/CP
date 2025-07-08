#include<bits/stdc++.h>
using namespace std;
int main()
{
string cipher;
cin >> cipher;
int n = cipher.length();
string decipher ="";
int mid_index = n%2==0 ? n/2-1 : n/2 ;
int left =mid_index-1,right=mid_index+1;
bool turn = true;
while(left>=0 || right<n){

    if(turn){
        decipher+=(cipher[right]);
        right++;
        turn=false;
    }else{
        decipher+=(cipher[left]);
        left--;
        turn=true;
    }
}
cout << cipher[mid_index]+decipher;
return 0;
}