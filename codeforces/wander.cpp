/*
problem link ->
https://codeforces.com/problemset/problem/1106/D
*/

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
#define p_arr(A,n)      loop(i,0,n) cout<<A[i]<<" ";
#define pln_arr(A,n)    loop(i,0,n) cout<<A[i]<<endl
#define take_n          int n; cin>>n;
#define take_arr        int arr[n]; loop(i,0,n) cin>>arr[i];
  
  
const int mod= 1e9+7;
const int inf= 1e15;
 
 
void solve(){
    int n,m; cin>>n>>m;
    vector<int> vis(n+1,0);
    vector<vector<int>> adj(n+1);
    loop(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi ans;
    minheap mh;
   mh.push(1); vis[1]=1;
    while(ans.size()+mh.size()<n){
        int x= mh.top();
        mh.pop();
        ans.pb(x);
        for(auto y: adj[x]){
            if(!vis[y]){
                vis[y]=1;
                mh.push(y);
            }
        }
    }

    while(!mh.empty()){
        int mini= mh.top();
        mh.pop();
       ans.pb(mini);
    }

    p_arr(ans,n);
    cout<<endl;

}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}