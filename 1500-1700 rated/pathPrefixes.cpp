/*
problem link->
https://codeforces.com/problemset/problem/1714/G
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, pair<int, int>>>> adj;
vector<int> ans;
vector<int> adist;
vector<int> bdist;
vector<int> level;
vector<int> par;
vector<vector<int>> up(1e5, vector<int> (20));



void dfs(int src){
    
    for(auto x: adj[src]){
      level[x.first]=level[src]+1;
      adist[x.first]=adist[src]+x.second.first;
      bdist[x.first]=bdist[src]+x.second.second;

      dfs(x.first);
    }
 


}

void solve(){
    int n; cin>>n;
    adj.clear();
    ans.clear();
    adist.clear();
    bdist.clear();
    par.clear();
    adj.resize(n+1);
    ans.resize(n+1);
    adist.resize(n+1);
    bdist.resize(n+1);
    par.resize(n+1);
    vector<int> level(n+1);

    for(int i=2; i<=n; i++){
        int anc,ai,bi;
        cin>>anc>>ai>>bi;
        
        adj[anc].push_back({i, {ai,bi}});
        par[i]=anc;
        up[i][0]=par[i];
    }

    
    
   
  
    adist[1]=0;
    bdist[1]=0;
    ans[1]=0;
    level[1]=0;

    dfs(1);

     for(int j=1; j<=20; j++){
       for(int node=1; node<=n; node++){
        if(j<=level[node])
        up[node][j]=up[up[node][j-1]][j-1];
       }
    }
    
    for(int i=2; i<=n; i++){
        int l=0; int r=level[i];

        //search within this range, maximum value such that bdist[k]<adist[i];
       
        while(l<=r){
            int x=i;
            int mid=(l+r)/2;

            for(int j=0; j<=20; j++){
                if(mid&(1<<j)){
                    x=up[i][j];
                }
            }

            if(bdist[x]>adist[i]){
              r=mid-1;
            }
            else{
             ans[i]=mid;
             l=mid+1;
            }
            
        }
    }

    for(int i=2; i<=n; i++) cout<<ans[i]<<" ";

    cout<<endl;

  

}

int main(){
    int t; cin>>t;

    while(t--) solve();

    return 0;
}