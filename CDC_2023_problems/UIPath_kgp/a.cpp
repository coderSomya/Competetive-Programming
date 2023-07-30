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

int n;
int mini;

void dfs(int src, vector<vector<pair<int,int>>> &adj, vector<int> &vis, int curr, int dist,  int k){

    if(dist>k){
        return;
    }

    if(src==n){
        mini=min(mini, curr); return;
    }

    vis[src]=1;
   
    for(auto x: adj[src]){
        int temp=curr;
        temp=max(temp, x.second);
        dfs(x.first, adj, vis, temp, dist+1, k);
    }

    vis[src]=0;
}
 
 
void solve(){

    
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}