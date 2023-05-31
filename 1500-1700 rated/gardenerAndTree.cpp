/*
problem link ->
https://codeforces.com/problemset/problem/1593/E
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k; cin>>n>>k;

    vector<set<int>> adj(n+1);
    for(int i=0; i<n-1; i++){
       int u, v; cin>>u>>v;
       adj[u].insert(v);
       adj[v].insert(u);
    }

   queue<int>q;
   for(int i=1; i<=n; i++){
     if(adj[i].size()<=1){
      q.push(i);
     }
   }

   q.push(-1);

   int removed=0;
   while(!q.empty() && removed<n && k>0){
     
     int x=q.front();
     q.pop();
     if(x==-1){
        k--; 
        q.push(-1);
        continue;
     }
     removed++;
     for(auto neigh: adj[x]){
        adj[neigh].erase(x);
        if(adj[neigh].size()<=1) q.push(neigh);
     }
   }

   int ans=n-removed;
   cout<<ans<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();
    
    return 0;
}