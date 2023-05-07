/*
problem link ->
https://codeforces.com/contest/1829/problem/D
*/

#include <bits/stdc++.h>
using namespace std;

const int N= 1e7+1;
vector<vector<int>> adj(N);
int n, m;

void dfs(int src, vector<int> &vis){
   
   vis[src]=1;
   if(src==m){
    return;
   }
   for(auto x: adj[src]){
    if(!vis[x]) dfs(x, vis);
   }

   return;

}
void solve(){
     cin>>n>>m;
    
    //check if there is a path from n to m;
    if(m>n){
        cout<<"NO"<<endl;
        return;
    }
    vector<int> vis(n+1,0);
    dfs(n, vis);

    if(vis[m]){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main(){

    int t; cin>>t;
    for(int i=3; i<N; i+=3){
            adj[i].push_back(i/3);
            adj[i].push_back(2*i/3);
    }
    
    while(t--) solve();

    return 0;
}