#include <bits/stdc++.h>
using namespace std;
#define loop(i,l,r)     for(int i=l; i<r; i++)
#define int             long long
#define pb              push_back
#define vi              vector<int>
#define mp              make_pair<int,int>
#define mod             1e9+7
#define inf             1e18
#define umpii           unordered_map<int,int>
#define maxheap         priority_queue<int>
#define minheap         priority_queue<int, vi,greater<int>>
#define setbits(x)      _builtin_popcountll(x)
#define zerobits(x)     _builtin_ctzll(x)
#define in_arr(A,n)     loop(i,0,n) cin>>A[i];
#define p_arr(A,n)      loop(i,0,n) cout<<A[i]
;
#define pln_arr(A,n)    loop(i,0,n) cout<<A[i]<<endl
#define take_n          int n; cin>>n;
#define take_arr        int arr[n]; loop(i,0,n) cin>>arr[i];
  
vector<vector<int>> g;
vector<int> vis;
bool is_bip;

void dfs(int node, int color){
    vis[node]=color;
    for(auto x: g[node]){
        if(vis[x]==-1){
            dfs(x, 1^color);
        }
        else{
            if(vis[node]==vis[x]){
                is_bip=false;
            }
        }
    }
}

//bipartite graph checks->
//1)there is no cycle of odd length
//2)alternate colourable;all edges connect opposite colors


void solve(){

    int n,m;
    cin>>n>>m;
    g.clear();
    vector<pair<int,int>> edges(m);
    edges.clear();
    g.resize(n+1);
    vis.assign(n+1,-1);
    is_bip=true;
    loop(i,0,m){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
        edges.push_back({a,b});
    }

    int comp_cnt=0;

    for(int i=1; i<=n; i++){
        if(vis[i]==-1){
            dfs(i,1);
        }
     
    }

  

    if(is_bip){
        cout<<"YES"<<endl;
        for(int i=0; i<m; i++){
            if(vis[edges[i].first]==0) cout<<0;
            else cout<<1;
        }
        cout<<endl;
    }

    else cout<<"NO"<<endl;
    
    
    }
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}