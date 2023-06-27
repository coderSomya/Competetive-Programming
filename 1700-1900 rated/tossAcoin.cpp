#include <bits/stdc++.h>
using namespace std;

int n,m,k;

int l; bool cyc;
int ct=0;
bool flag;
vector<int> vistime;

void dfs(int src, vector<int> &vis, vector<vector<int>> &adj, vector<int> &val, int maxi){
    vis[src]=ct;
    l++;
    if(l>=k) return;
    // vistime[src]=++ct;
    for(auto x: adj[src]) {
        if(val[x]>maxi) continue;
        if(vis[x]==ct)
        {   
            //isi dfs me mila hai
            cyc=true; return;
        }
        
        dfs(x, vis, adj, val, maxi);
        //........
        //........
    }
    l--;

}
bool check(int maxi, vector<vector<int>> & adj, vector<int> &val){
     vistime.resize(n+1, 0);
    vector<int> vis(n+1, 0);
    
    for(int i=1; i<=n; i++){
        l=0; cyc=false; flag=false;
        if(val[i]<=maxi && (vis[i]==0)){
            ct++;
            dfs(i, vis, adj, val, maxi);
        }
        
        if(flag || cyc) return true;
    }

    return false;
}

void solve(){
  cin>>n>>m>>k;

  vector<vector<int>> adj(n+1);

  vector<int> val(n+1);
  for(int i=0; i<n; i++) cin>>val[i+1];

  for(int i=0; i<m; i++){
    int u,v; cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int l=1; int h=1e9;
  int ans=-1;
  while(l<=h){
    int mid = (l+h)/2;

    if(check(mid, adj, val)){
        ans=mid;
        h=mid-1;
    }
    else l=mid+1;
  }

  cout<<ans<<endl;


}

int main(){
    solve();
    return 0;
}