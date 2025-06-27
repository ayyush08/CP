    #include<bits/stdc++.h>
    using namespace std;
    #define int long long


    bool canMakeBurger(int rubles,int nb,int ns,int nc,int pb,int ps,int pc,int bg_b,int bg_s,int bg_c,int X){
        int nb_total = X*bg_b;
        int ns_total = X*bg_s;
        int nc_total = X*bg_c;

        int canBuy_b = max(nb_total-nb, 0LL);
        int canBuy_s = max(ns_total-ns, 0LL);
        int canBuy_c = max(nc_total-nc, 0LL);

        int tot = canBuy_b*pb+canBuy_c*pc+canBuy_s*ps;

        return tot<=rubles;

    }
    signed main()
    {
    string recipe; cin >> recipe;
    int nb,ns,nc; cin >> nb >> ns >> nc;
    int pb,ps,pc; cin >> pb >> ps >> pc;
    int rubles; cin >> rubles;

    int burger_b=0,burger_s=0,burger_c=0;

    for(char c:recipe){
        if(c=='B') burger_b++;
        if(c=='S') burger_s++;
        if(c=='C') burger_c++;
    }
    int l=0,r=1e13;
    int ans=0;

    while(l<=r){
        int mid = (l+r)/2;
        if(canMakeBurger(rubles,nb,ns,nc,pb,ps,pc,burger_b,burger_s,burger_c,mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }

    cout << ans ;


    return 0;
    }

    //Is it possible to make L hamburgers using at most r rubles.