/*
problem link ->
https://codeforces.com/problemset/problem/1611/E1
*/

#include <bits/stdc++.h>
using namespace std;

//idea: we maintain the fact that wether we are reaching a node first from the root or from any friends node..

//this can be maintained by storing a color for each node the first time it is seen

void solve(){
      int n,k; cin>>n>>k;
      vector<int> color(n+1,-1);
      queue<int>q;
      
      color[1]=0;
      for(int i=0; i<k; i++){
        int x; cin>>x;
        color[x]=1; //set color of friend
        q.push(x); //insert friends
      }
      q.push(1);//insert root

      vector<vector<int>> adj(n+1);
      for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
      }

      while(!q.empty()){
        int x=q.front();
        q.pop();

        for(auto ch: adj[x]){
            if(color[ch]==-1){
                color[ch]=color[x];
                //assigning color to nearest uncolored guy
                q.push(ch);
            }
        }
      }


      for(int i=2; i<=n; i++){
        if(adj[i].size()==1 && color[i]==0){
            cout<<"YES"<<endl;
            return;
        }
      }

      cout<<"NO"<<endl;
}

int main()
{
    int t; cin>>t;
    while(t--) solve();

    return 0;
}