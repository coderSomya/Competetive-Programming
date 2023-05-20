/*
problem link ->
https://codeforces.com/problemset/problem/1693/B
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<vector<int>> adj;
int n;

vector<int> l,r;
int ans;

int count(int src){

  int sum=0;
  for(auto x: adj[src]) sum+=count(x);

  if(sum<l[src]){
    ans++;
    return r[src];
  } 
  return min(r[src], sum);
}

void solve(){
    cin>>n;
    adj.clear();
    adj.resize(n+1);
    for(int i=2; i<=n; i++){
       int x; cin>>x;
       adj[x].push_back(i);
    }
    ans=0;

    l.clear();
    r.clear();
    l.resize(n+1);
    r.resize(n+1);

    for(int i=1; i<=n; i++){
        cin>>l[i]>>r[i];
    }
   
   int _ =count(1);

   cout<<ans<<endl;


}

int32_t main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}