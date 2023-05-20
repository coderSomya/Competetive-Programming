/*
problem link->
https://codeforces.com/problemset/problem/1702/E
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;

bool flag;

void dfs(int src, int par, int curr){

    vis[src]=1;
    curr++;
    // cout<<src<<" "<<curr<<endl;

    for(auto x: adj[src]){
        if(x!=par)
        {
            if(vis[x]){
                //found a cycle
                if(curr%2)
                {
                    flag=true;
                 
                    return;
                }
            }
            else dfs(x,src, curr);
        }
    }
    curr--;
    vis[src]=0;
    
}

void solve(){
    int n; cin>>n;
    vector<pair<int,int>> v;

    adj.clear();
    adj.resize(n+1);
    vis.clear();
    vis.resize(n+1,0);
    set<pair<int,int>> st;
    for(int i=0;i<n; i++){
    int x,y; cin>>x>>y;
    if(st.find({min(x,y), max(x,y)})!=st.end()) continue;
    st.insert({min(x,y), max(x,y)});
   adj[x].push_back(y);
   adj[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]){
          
            flag=false;
            dfs(i,0,0);
            if(flag){
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    //not possible if there are odd length cycles


    cout<<"YES"<<endl;
}

int main(){
  int t; cin>>t;
  while(t--) solve();

  return 0;
}