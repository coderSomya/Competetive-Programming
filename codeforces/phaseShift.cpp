/*
problem link ->
https://codeforces.com/problemset/problem/1735/C
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
    vector<vector<int>>g;

void dfs(int src, vector<int> &vis){
    cout<<"here"<<endl;
    vis[src]=1;
    for(auto x: g[src]){
        if(!vis[x]) dfs(x, vis);
    }
}
 
 
void solve(){
    take_n
    string t; cin>>t;
    string s; 
g.clear();

    loop(i,0,n) {
    
    //mark all edges in the path of t[i]-'a' as visited
     vi vis(26,0);
     dfs(i, vis);
     loop(j,0,26){
         if(!vis[j]) {
            s+='a'+j;
            g[t[i]-'a'].pb(j);
            g[j].pb(t[i]-'a');
            break;
         }
     }
     
    }

    cout<<s<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}