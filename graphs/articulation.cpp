#include <bits/stdc++.h>
using namespace std;

vector<int> articulation;

int timer=1;

void dfs(int src, int par, vector<int> &vis, int tin[], int low[], vector<vector<int>> &adj){
 
     vis[src]=1;
    tin[src]=low[src]=timer++;
    int child=0;

    for(auto x: adj[src]){
        if(x==par) continue;


        if(vis[x]){
            low[src]=min(low[src], tin[x]);
        }

        else{
            child++;
            dfs(x, src, vis, tin, low, adj);

            low[src]=min(low[src], low[x]);
            if(low[x]>=tin[src] && par!=0){
                articulation.push_back(src);
            }
         
        }
    }

    if(par==0 && child>1){
        articulation.push_back(1);
    }
}

void solve(){
    int n; cin>>n;
    int m; cin>>m;
    vector<vector<int>>adj(n+1);

    int tin[n+1];
    int low[n+1];
    vector<int> vis(n+1, 0);
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


   dfs(1, 0, vis, tin, low, adj);

//    for(auto x: articulation) cout<<x<<" ";
//    cout<<endl;

//    for(int i=1; i<=n;i++) cout<<tin[i]<<" ";
//    cout<<endl;

//    for(int i=1; i<=n;i++) cout<<low[i]<<" ";
//    cout<<endl;


}

int main()
{
    int t; cin>>t;
    while(t--) solve();

    return 0;
}