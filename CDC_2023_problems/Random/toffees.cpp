#include <bits/stdc++.h>
using namespace std;
#define loop(i,l,r)     for(int i=l; i<r; i++)
#define int             long long
#define pb              push_back
#define vi              vector<int>
#define mkp             make_pair<int,int>
#define umpii           unordered_map<int,int>
#define maxheap         priority_queue<int>
#define minheap         priority_queue<int, vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)     __builtin_ctzll(x)
#define in_arr(A,n)     loop(i,0,n) cin>>A[i];
#define p_arr(A,n)      loop(i,0,n) cout<<A[i]
;
#define pln_arr(A,n)    loop(i,0,n) cout<<A[i]<<endl
#define take_n          int n; cin>>n;
#define take_arr        int arr[n]; loop(i,0,n) cin>>arr[i];
  
  
const int mod= 1e9+7;
const int inf= 1e15;

int dp[1000][10000];
int n,t;
vi vis(1000);

vector<vector<pair<int,int>>> v(1000);

int rec(int i, int t){

    if(i==n) return 0;

    if(dp[i][t]!=-1) return dp[i][t];

    int temp=rec(i+1,t);

    for(auto x: v[i]){
        if(x.first<=t) temp=max(temp, x.second+ rec(i+1, t-x.first));
    }

    return dp[i][t]=temp;



}

void dfs(int src, int par, int ct, vector<vector<int>> &adj, vector<int> &vis){
    vis[src]=ct;

    for(auto x: adj[src]){
        if(x!=par && vis[src]==0){
           dfs(x,src, ct, adj, vis);
        }
    }
}
 
 
void solve(){

    cin>>n>>t;

    vi ci(n+1), mi(n+1);
    loop(i,1,n+1) cin>>ci[i];
    loop(i,1,n+1) cin>>mi[i];

    int m; cin>>m;
    vector<vector<int>> adj(n+1);

    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int ct=-1;
    vis.assign(n+1, 0);
    memset(dp, -1, sizeof(dp));


    for(int i=1; i<=n; i++){
        if(vis[i]!=0) continue;
        ct++;
        dfs(i, 0, ct, adj, vis);

        for(int j=1; j<=n; j++){
            if(vis[j]==ct){
                v[ct].pb({ci[j], mi[j]});
            }
        }
    }

    // for(auto x)

    n=ct+1;

    int ans=rec(0, t);
    cout<<ans<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}