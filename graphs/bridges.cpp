#include <bits/stdc++.h>
using namespace std;

int timer=1;

vector<pair<int,int>> bridges;

void dfs(int src, int par, vector<int> &vis, vector<int> adj[], int tin[], int low[]){

    vis[src]=true;
   tin[src]=low[src]=timer++;
    for(auto x: adj[src]){
        if(x==par) continue;

        if(vis[x]){
            low[src]=min(low[src], low[x]);
        }
        else{
            dfs(x, src, vis, adj, tin, low);
            low[src]=min(low[src], low[x]);

            //src-x bridge?
            if(low[x]> tin[src]){
                    bridges.push_back({src, x});
            }
        }
    }
}

void solve(){
    int n; cin>>n;
    vector<int> adj[n+1];

    int m; cin>>m;

    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n+1,0);

    int tin[n+1];
    int low[n+1];

   dfs(1, 0, vis, adj, tin, low);

   for(auto x: bridges){
    cout<<x.first<<"---"<<x.second<<endl;
   }

}

int main(){
    int t; cin>>t;
    while(t--) solve();
}