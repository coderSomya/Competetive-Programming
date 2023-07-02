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

set<int> edges;
map<pair<int,int>, int> mp;

 
int dfs(int src, int par, vector<vector<int>> &adj){

    int temp=0;

    for(auto x: adj[src]){
        if(x!=par){
            temp+=dfs(x, src, adj);
        }
    }

    temp+=1;
    if(temp==3){
        // cout<<"src - par"<<endl;
        // cout<<src<<" "<<par<<endl;
        edges.insert(mp[{min(src, par), max(src, par)}]);
        return 0;
    }

    return temp;
}
 
void solve(){
    int n; cin>>n;
    vector<vector<int>> adj(n+1);
    mp.clear();
    edges.clear();

    for(int i=0; i<n-1; i++){
       int u,v; cin>>u>>v;

       adj[u].push_back(v);
       adj[v].push_back(u);

       mp[{min(u,v), max(u,v)}]=i+1;
    }

    mp[{0,1}]=0;

    

    int a = dfs(1,0,adj);
    edges.erase(0);

    if(n%3!=0){
        cout<<"-1"<<endl;
        return;
    }

    if(edges.size()== (n/3)-1){
        cout<<edges.size()<<endl;
        for(auto x: edges) cout<<x<<" ";
        cout<<endl;
    }
    else cout<<-1<<endl;
    
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}