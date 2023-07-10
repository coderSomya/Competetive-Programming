#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;

vector<int> vis;
vector<int> col;
bool flag;

void dfs(int src, int par){

    vis[src]=1;
    
    for(auto x: adj[src]){
        if(col[x]==col[src]){
            if(vis[x]){
                flag=true;
                return;
            }
            else continue;
            //suspicious
        }
        else{
            if(vis[x]){
              continue;
            } 
            dfs(x, src);
        }
    }

    vis[src]=0;

}

void solve(){

int n,m; cin>>n>>m;
adj.clear();
adj.resize(n+1);

flag=false;

for(int i=0; i<m; i++){
    int u,v; cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vis.clear();
vis.resize(n+1,0);
col.clear();
col.resize(n+1);

for(int i=0; i<n; i++){
    cin>>col[i+1];
}

dfs(1,0);

if(flag) cout<<"Yes"<<endl;
else cout<<"No"<<endl;


}

int main(){
    // int t; cin>>t;
    // while(t--) 
    solve();

    return 0;
}