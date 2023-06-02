/*
problem link->
https://codeforces.com/problemset/problem/1562/D1
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,q; cin>>n>>q;
    string s; cin>>s;
    
    int arr[n];
    for(int i=0;i<n; i++) arr[i]=pow(-1,i+1)*(s[i]=='+'?1:-1);

    int pref[n]; pref[0]=arr[0];
    for(int i=1; i<n; i++) pref[i]=pref[i-1]+arr[i];

    while(q--){
        int l,r; cin>>l>>r;
        l--; r--;
        int res=pref[r]-(l>0? pref[l-1]:0);
        if(res==0){
            cout<<0<<endl;
        }
        else if(res%2){
            cout<<1<<endl;
        }
        else cout<<2<<endl;
    }
}

int main()
{
    int t; cin>>t;
    while(t--) solve();

    return 0;
}