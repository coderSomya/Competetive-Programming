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

void dfs(int src, int par, vector<vector<int>> &adj, vector<int> &leaf){
   
   int temp=0;
   if(src!=1 && adj[src].size()==1) {
    leaf[src]=1;
    return;
   }

    for(auto x: adj[src]){
        if(x!=par){
            dfs(x, src, adj, leaf);
            temp+= leaf[x];
        }
    }

    leaf[src]=temp;
}
 
 
void solve(){
    take_n
    vector<vector<int>> adj(n+1);

    loop(i,0,n-1){
        int x, y; cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

   vector<int> leaf(n+1, 0);
    dfs(1, -1, adj, leaf);

    int q; cin>>q;
    while(q--){
        int x,y;
         cin>>x>>y;
         int ans=0;
         ans=leaf[x]*leaf[y];
         cout<<ans<<endl;
    }

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}