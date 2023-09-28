/*
problem link->
https://codeforces.com/problemset/problem/1873/H
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> temp;

const int inf = 1e9;

void dijkstra(int src, int n,  vector<vector<int>> &adj, vector<int> &dist){
  
  dist[src]=0;

   priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

   pq.push({0,src});
   

   while(!pq.empty()){
      pair<int,int>p = pq.top();

      int wt= p.first;
      int node= p.second;

      pq.pop();

      for(auto x: adj[node]){
        if(dist[node]+1<dist[x]){
            dist[x]=dist[node]+1;
            pq.push({dist[x], x});
        }
      }
   }
}

void dfs(int src, int par, vector<vector<int>> &adj, int color[], int parent[]){

    if(color[src]==2){
        //already visited
        return;
    }


    if(color[src]==1){
        //visited in this round
        vector<int> v;
        
        int curr= par;
        v.push_back(curr);
        while(curr!=src){
            curr= parent[curr];
            v.push_back(curr);
        }
        temp=v;
        return;
    }

    parent[src]=par;

    //mark src visited in this round
    color[src]=1;

    for(auto x: adj[src]){
        if(x==parent[src]) continue;

        dfs(x, src, adj, color, parent);
    }

    color[src]=2;
}

void solve(){
  
    int n,a,b;
    cin>>n>>a>>b;

    temp.clear();

    vector<vector<int>> adj(n+1);
    int color[n+1]={0};
    int parent[n+1]={0};

    for(int i=0; i<n; i++){
        int u, v; cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, adj, color, parent);

    vector<int> dist(n+1, inf);
    vector<int> dist2(n+1, inf);

    dijkstra(b,n, adj, dist);
    dijkstra(a,n, adj, dist2);
    
  bool flag = false;

    for(auto x: temp){
        if(dist[x]<dist2[x]){
            flag=true;
        }
    }

    if(flag){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}