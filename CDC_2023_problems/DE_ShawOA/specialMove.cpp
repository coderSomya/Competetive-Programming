#include <bits/stdc++.h>
using namespace std;


void dfs(int src, int par, vector<int> &dist, vector<vector<int>> &adj, int val[]){

    for(auto x: adj[src])
    {
        if(x!=par) dfs(x, src, dist, adj, val);
    }
    
    int temp=0;

    for(auto x: adj[src]){
        temp=max(temp, dist[x]);
    }

    dist[src]=val[src]+temp;


}

void solve(){
  int n; cin>>n;
  int val[n+1];
  for(int i=1; i<=n; i++) cin>>val[i];

  vector<vector<int>> adj(n+1);

  for(int i=0; i<n-1; i++){
     int u,v; cin>>u>>v;
     adj[u].push_back(v);
     adj[v].push_back(u);
  }

  vector<int> dist(n+1, 0);

   dfs(1, 0, dist, adj, val);

   int maxi=0; int smaxi=0;

   for(auto x: adj[1]){
         if(dist[x]>=maxi){
            
            smaxi=maxi;
            maxi=dist[x];
         }
         else if(dist[x]>smaxi){
            smaxi=dist[x];
         }
   }

   cout<<maxi+smaxi+val[1]<<endl;


}


int main()
{
    int t; cin>>t;
    while(t--) solve();

    return 0;
}