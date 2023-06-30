#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;

vector<int> maxdown(N);
vector<int> maxup(N);

//inout dfs

void dfs(int src, int par, vector<set<int>> &adj){
   
   int maxi=0;
   for(auto x: adj[src]){
    if(x!= par){
        dfs(x,src, adj);
    }
   }
   for(auto x: adj[src]){
    if(x!=par){
        // st.insert(maxdown[x]);
        maxi=max(maxdown[x], maxi);
    }
   }


   maxdown[src]=1+maxi;

 
}

void dfs2(int src, int par, vector<set<int>> &adj){
    
     multiset<int> st;
   for(auto x: adj[src]){
    if(x!=par){
        st.insert(maxdown[x]);
        // maxi=max(maxdown[x], maxi);
    }
   }

   for(auto x: adj[src]){
    if(x!=par){
        st.erase(st.find(maxdown[x]));
        
        if(st.empty()) maxup[x]=2;
        else maxup[x]=*(--st.end())+2;
        maxup[x]=max(maxup[x], maxup[src]+1);

        st.insert(maxdown[x]);

        dfs2(x, src, adj);
    }
   }


}

void solve(){
    int n; cin>>n;

    vector<set<int>>adj(n+1);

    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    maxup.clear();
    maxup.resize(n+1,1);
    maxdown.clear();
    maxdown.resize(n+1);

    dfs(1,-1,adj);
    dfs2(1,-1,adj);

    map<int,int> mp;
    for(int i=1; i<=n; i++){
        int maxi=max(maxdown[i], maxup[i]);
        mp[maxi-1]++;
    }

   int curr=1;
    for(int i=1; i<=n; i++)
    {
       if(mp.find(i-1)!=mp.end()){
        curr+= mp[i-1];
       }

       cout<<min(n, curr)<<" ";
    }


    cout<<endl;

}


int main(){
    
     solve();

    return 0;
}
