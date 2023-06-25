#include <bits/stdc++.h>
using namespace std;
set<int> st;
int source,dest;
vector<int> type;

void dfs(int src, int par, vector<vector<int>> &adj){

    if(adj[src].size()==1 && src!=source){
        //is leaf
        if(src==dest) type[src]=1;
        else if(st.find(src)!=st.end()) type[src]=2;

        else type[src]=0;
        return;
    }

    for(auto x: adj[src]){
    if(x!=par)
    {
         dfs(x, src, adj);
    }
    }
    
    bool wun=false;
    bool tus=false;
    for(auto x: adj[src]){
        if(x!=par){


       if(type[x]==1){
            wun=true;
        }
        if(type[x]==2){
            tus=true;
        }
        }
      
    }

    if(src==dest) wun=true;
    if(st.find(src)!=st.end()) tus=true;

    if(wun) type[src]=1;
    else if(tus) type[src]=2;
    else type[src]=0;

    if(src==source) type[src]=0;
}
void solve(){

    int n, k; cin>>n>>k;
    int x, y; cin>>x>>y;
    source=x;
    dest=y;
    st.clear();
    for(int i=0; i<k; i++){
        int l; cin>>l;
        st.insert(l);
    }
    type.resize(n+1,0);

    vector<vector<int>> adj(n+1);
   
    //type=2 ->contains any work
    //type=1 ->contains dest

    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(x, -1, adj);
   int ans=0;
    for(int i=1; i<=n; i++){
        ans+= type[i];
    }

    cout<<ans<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}