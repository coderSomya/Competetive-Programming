#include <bits/stdc++.h>
using namespace std;

const int N= 2e5+5;

int dp[N];
int vis[N];
int col[N];

int ct;


void dfs(int src, vector<vector<int>> &adj){
    
    dp[src]=ct;
    vis[src]=1;

    for(auto x: adj[src]){
       if(vis[x]) continue;

       if(col[x]==col[src]) continue;

       dfs(x, adj);
    }
}

void solve(){
    memset(dp, -1, sizeof(dp));
    memset(vis, 0,sizeof(vis));

    int n,m; cin>>n>>m;
    ct=0;
    vector<vector<int>> adj(n+1);

    vector<pair<int,int>> edges;

    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        edges.push_back({u,v});
    }
  for(int i=0; i<n; i++){
    cin>>col[i+1];
  }
    

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            ct++;
            dfs(i, adj);
        }
    }

//  for(int i=0; i<n;i++) cout<<col[i+1]<<endl;

    for(auto x: edges){
        if(col[x.first]!=col[x.second]) continue;
        if(dp[x.first] == dp[x.second]) {
            // cout<<x.first<<" "<<x.second<<endl;
            cout<<"Yes"<<endl;
            return;
        }
    }


  cout<<"No"<<endl;



    
}

int main(){
    // int t; 
    // scanf("%d", &t);
    // while(t--) 
    solve();

    return 0;
}