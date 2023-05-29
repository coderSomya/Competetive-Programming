/*
problem link-
https://codeforces.com/problemset/problem/1621/C
*/

#include <bits/stdc++.h>
using namespace std;

int query(int i){
    int response;
    cout<<"? "<<i<<endl;
    cin>>response;

    return response;
}

void solve(){
    int n; 
    cin>>n;

    vector<vector<int>> adj(n+1);

    vector<int>vis(n+1,false);
   
    
    for(int i=1; i<=n; i++){
      int prev=0;
      if(!adj[i].empty()) continue;
      int x= query(i);
      if(x==prev) continue;
      if(vis[x]==2) continue;

      else{
        vis[x]++;
        if(prev!=0) adj[prev].push_back(x);
        prev=x;
        i--;
      }
    }

    for(int i=1; i<=n; i++) {
        if(adj[i].size()==0) cout<<i<<endl;
        else cout<<adj[i][0]<<endl;
    }

}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}