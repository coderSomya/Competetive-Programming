#include <bits/stdc++.h>
using namespace std;


bool flag;
// set<int> st;


set<int> merge(set<int> &a, set<int> &b){
    if((int)a.size()< (int)b.size()) swap(a,b);

    for(auto x: b) a.insert(x);

    return a;
}

bool check(set<int> &a, int k){

    if(a.empty()) return true;
    auto x =  a.upper_bound(k-1);
    if(x!=a.end()) return false;

    // if(a.size()<k-1) return false;

    return true;
}

vector<int> sz(2000);

set<int> dfs(int src ,vector<vector<int>> &adj, vector<int> &val, int k){
   set<int> st;
   for(auto x: adj[src]){
      set<int>ast=dfs(x, adj, val, k);
      st=merge(st, ast);
   }

   if(val[src]!=-1) st.insert(val[src]);


   if(check(st, k)) {
     if(sz[src]==1){
        if((int)st.size()>=k-1) flag=true;
     }
     if(sz[src]==0){
        if((int)st.size()==k) flag=true;
     }
   }



   return st;
}


void vacant(int src, vector<vector<int>> &adj, vector<int> &val){

    for(auto x: adj[src]) vacant(x, adj, val);

    for(auto x: adj[src]) sz[src]+= sz[x];

    sz[src]+=(val[src]==-1);
}

void solve()
{
    int n,k; cin>>n>>k;
    vector<vector<int>> adj(n+1);
    vector<int> val(n+1);
    for(int i=2; i<=n; i++){
        int par; cin>>par;
        adj[par].push_back(i);
    }

    for(int i=1; i<=n; i++) cin>>val[i];
    
    // st.clear();
    sz.clear();
    sz.resize(n+1,0);
    vacant(1, adj, val);
    flag=false;
    set<int> _ =  dfs(1, adj, val, k);


    // for(auto x: _) cout<<x<<" ";
    // cout<<endl;

    if(flag) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;

}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}
