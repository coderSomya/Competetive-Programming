/*
problem link ->
https://codeforces.com/problemset/problem/1263/D
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
#define p_arr(A,n)      loop(i,0,n) cout<<A[i]
;
#define pln_arr(A,n)    loop(i,0,n) cout<<A[i]<<endl
#define take_n          int n; cin>>n;
#define take_arr        int arr[n]; loop(i,0,n) cin>>arr[i];
  
  
const int mod= 1e9+7;
const int inf= 1e15;

vector<vi> adj;
 
void dfs(int src, vector<bool> &vis){
   
   vis[src]=1;

   for(auto x: adj[src]){
    if(!vis[x]) dfs(x, vis);
   }
} 
void solve(){

    take_n
    vector<vi> v(26);
    loop(i,0,n){
        string s; cin>>s;
        vi seen(26,0);
     
        for(char ch: s){
            if(seen[ch-'a']) continue;
           v[ch-'a'].pb(i);
           seen[ch-'a']=1;
        }
    }
  adj.clear(); adj.resize(n);

    
    loop(i,0,26){
      
        for(int j=0; j+1<v[i].size(); j++){

        
            adj[v[i][j]].pb(v[i][j+1]);
            adj[v[i][j+1]].pb(v[i][j]);
        }
    }


    int ans=0;
    vector<bool> vis(n,0);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            ans++;
            dfs(i,vis);
        }
    }

    cout<<ans<<endl;



}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}