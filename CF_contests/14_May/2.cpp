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
vi vis;
int g;

void dfs(int src){
    
    vis[src]=1;
    int temp;
    for(auto x: adj[src]){
        if(vis[x]!=1){
          g=__gcd(g, abs(x-src));
          dfs(x);
        }
    }

    return;

}
 
void solve(){

  int n; cin>>n;
  adj.clear();
  vis.clear();
  adj.resize(n+1);
  vis.resize(n+1,0);
  for(int i=1;i<=n; i++){
    int x; cin>>x;
    adj[i].push_back(x);
  }
  int ans=0;
  for(int i=1; i<=n;i++){
    if(!vis[i]){
        g=0;
        dfs(i);
        ans=__gcd(ans, g);
    }
  }

  cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}