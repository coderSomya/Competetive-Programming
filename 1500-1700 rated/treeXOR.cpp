/*
problem link ->
https://codeforces.com/problemset/problem/1760/G
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj;
vector<int> axor;
vector<int> bxor;
set<int>st;
bool flag;

void dfs(int src, int par, int curr, int turn, vector<int> &v){
    
    v[src]=curr;
    if(turn) st.insert(curr);
    
    for(auto x: adj[src]){
        if(x.first!=par){
            int temp=curr^x.second;
            dfs(x.first, src,temp, turn, v);
        }
    }

}

void solve(){

   int n,a,b;
   cin>>n>>a>>b;
   flag=false;
   st.clear();
   adj.clear();
   axor.clear();
   bxor.clear();
   adj.resize(n+1);
   axor.resize(n+1);
   bxor.resize(n+1);

   for(int i=0; i<n-1; i++){
    int u,v,w; cin>>u>>v>>w;

    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
   }

   //find xor to all nodes with a as the root
   dfs(a,-1, 0, 1, axor);
   
   if(axor[b]==0){
    cout<<"YES"<<endl;
    return;
   }

   //find xor to all nodes with b as the root
   dfs(b,-1,0,0, bxor);
   for(int i=1; i<=n; i++){
    if(i!=a && i!=b){
        if(st.find(bxor[i])!=st.end()){
            cout<<"YES"<<endl;
            return;
        }
    }
   }
 

   //if xor[a][b] == 0 or if there are any two equal values the anwer is yes 

   cout<<"NO"<<endl;

}

int main(){
    int t; cin>>t;
    while(t--) solve();


    return 0; 
}