/*
problem link ->
https://codeforces.com/problemset/problem/1626/C
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int sum(int l, int r){
    return (r-l)*(r-l+1)/2;
}

void solve(){
    int n; cin>>n;
    int k[n],h[n];

    for(int i=0; i<n; i++) cin>>k[i];
    for(int i=0; i<n; i++) cin>>h[i];

    vector<pair<int,int>>spells;

    for(int i=0; i<n; i++) spells.push_back({k[i]-h[i], k[i]});

    sort(spells.begin(), spells.end());



//    for(int i=0; i<n; i++) cout<<spells[i].first<<" "<<spells[i].second<<endl;
    int l=-1,r=-1;
    int ans=0;
    int last=-1;

    for(int i=0; i<n; i++){
       if(spells[i].first>=r){
         ans+=sum(l,r);
         l=spells[i].first;
         r=spells[i].second;
       }
       else{
        r=max(r,spells[i].second);

       }   
    }
    
    ans+=sum(l,r);

    cout<<ans<<endl;

    
}

int32_t main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}