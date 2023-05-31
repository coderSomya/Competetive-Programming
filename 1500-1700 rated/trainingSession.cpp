/*
problem link->
https://codeforces.com/problemset/problem/1598/D
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n; cin>>n;
    int a[n],b[n];
    for(int i=0; i<n; i++) cin>>a[i]>>b[i];

    int freqA[n+1]={0}, freqB[n+1]={0};
    int ans=n*(n-1)*(n-2)/6;
    for(int i=0; i<n; i++){
       freqA[a[i]]++;
       freqB[b[i]]++;
    }

    for(int i=0; i<n; i++){
        int w= (freqA[a[i]]-1)*(freqB[b[i]]-1);

        ans-=w;
    }

    cout<<ans<<endl;
}

int32_t main(){
  int t; cin>>t;
  while(t--) solve();

  return 0;
}
