/*
problem link->
https://codeforces.com/problemset/problem/1872/F
*/

#include <bits/stdc++.h>
using namespace std;

int mini;
int who;


const int inf = 1e9+4;


void dfs(int src, int par, vector<int> &adj, vector<int> &vis, int cost[]){

    vis[src]=1;
   
    if(cost[src]<mini){
        mini=cost[src];
        who=src;
    }

    src=adj[src];
    par=src;

    if(!vis[src]) dfs(src, par, adj, vis, cost);
}




void solve(){
    int n; cin>>n;
    int arr[n+1];
    for(int i=1; i<=n; i++) cin>>arr[i];
    int cost[n+1];
    for(int i=1; i<=n; i++) cin>>cost[i];

    set<int> st;
    for(int i=1; i<=n; i++){
   st.insert(arr[i]);
    }
    int m=st.size();
    
    vector<int> adj(n+1);

    for(auto x: st){
        adj[x]=arr[x];
    }


    vector<int> vis(n+1,0);

    for(int i=1; i<=n; i++){
        if(st.count(i)==0) cout<<i<<" ";
    }

    for(int i=1; i<=n; i++)
    {   
        if(!vis[i] && st.count(i)!=0){
            mini=inf;
            who=-1;
            dfs(i,0,adj,vis,cost);

            int curr=adj[who];
            int par=-1;

            

            while(!(curr==adj[who] && par!=-1)){
               cout<<curr<<" ";
               curr=adj[curr];
               par=curr;
            }
        }
    }

    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}