/*
problem link->
https://codeforces.com/problemset/problem/1644/D
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod= 998244353;

void solve(){
    int n,m,k,q;
    cin>>n>>m>>k>>q;

    unordered_set<int>row;
    unordered_set<int>column;
    int ans=1;


    while(q--){

      int x,y;
      cin>>x>>y;
      if(row.size()==n || column.size()==m || (row.find(x)!=row.end() && column.find(y)!=column.end())){
        continue;
      }
      ans=(ans*k)%mod;
      row.insert(x); column.insert(y);
    }

    cout<<ans<<endl;

}

int32_t main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}