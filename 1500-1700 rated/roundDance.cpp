/*
problem link ->
https://codeforces.com/problemset/problem/1833/E
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> vis;
vector<int> vistime(2e6,-1);
int timer=0;
int cycles;

void dfs(int src, int par, vector<vector<int>> &adj){
   

   vis[src]=1;
   vistime[src]=timer;
   timer++;

   for(auto x: adj[src]){
    if(x==par) continue;
    if(!vis[x]){
        dfs(x,src,adj);
    }
    else{
        if(x!=par && vistime[x]<vistime[src]){
            cycles++;
        }
    }
   }

   return;

}

void solve(){
    int n; cin>>n;
    vector<vector<int>> adj(n+1);
    vis.clear();
    vistime.clear();
    vis.resize(n+1, 0);
    cycles=0;
    for(int i=1; i<=n; i++){
     int x; cin>>x;

     adj[i].push_back(x);
     adj[x].push_back(i);
    }


   int cc=0;
    for(int i=1; i<=n; i++){

        if(vis[i]==0){
           cc++;
           dfs(i,0,adj);
        }
  
    }



    int maxi= cc;
    int mini=cycles+(cc!=cycles);

    cout<<mini<<" "<<maxi<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();


    return 0;
}