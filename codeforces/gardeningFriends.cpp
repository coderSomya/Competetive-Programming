/*
problem link ->
https://codeforces.com/problemset/problem/1822/F
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> height(1e6);
int dfs(vector<vector<int>> &adj, int src, int par){
   int temp=0;
   for(auto x: adj[src]){
    if(x!=par){
        temp=max(temp,dfs(adj,x,src));
    }
   }

   return height[src] = 1+temp;
}

vector<vector<pair<int,int>>> v(1e6);

void max2(vector<vector<int>> &adj, int src, int par){
    
    pair<int,int> maxi={0,0};pair<int,int> smaxi={0,0};

    for(auto x: adj[src]){
        if(x!=par && height[x]>maxi.second){
            smaxi=maxi;
            maxi={x,height[x]};
        }
        else if(x!=par && height[x]>smaxi.second){
      smaxi={x,height[x]};
        }
    }

    v[src].push_back(maxi);
    v[src].push_back(smaxi);
}


void solve(){
    int n,k,c;
    cin>>n>>k>>c;

    vector<vector<int>>adj(n+1);

    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }

    int edges= dfs(adj, 1, -1)-1;
    int sum=k*edges;
    int prev=-1;
    int root=1;
  int ans=sum;
//    for(int i=1; i<n+1; i++){
//     cout<<height[i]<<" ";
//    }
   while(sum>0){

     max2(adj, root, prev);
     prev=root;
     sum+= (v[root][1].second-1)*(k-c);
     ans=max(ans, sum);
     sum-= (v[root][1].second-1)*(k-c);
     sum-=k;
     if(adj[root].size()<2) break;
     root=v[root][0].first;
   }
  
  cout<<ans<<endl;
}
int main(){

    int t; cin>>t;
    while(t--) solve();
    return 0;
}