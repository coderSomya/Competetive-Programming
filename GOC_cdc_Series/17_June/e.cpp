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


map<pair<int,int>, int> mp;

void dfs(int src, int par, vector<int> &dist, int n){

    if(src==1) dist[src]=0;
    else dist[src]=dist[par]+mp[{par,src}];
    
    if(2*src < n){
        dfs(2*src, src, dist, n);
        dfs(2*src+1, src, dist, n);
    }

}
 
 
void solve(){

    int n; cin>>n;

 
    int leaf= log2(1+n);
    vector<int> v(leaf, 0);

    // vector<vector<pair<int,int>>> adj(n+1);
   mp.clear();
    loop(i,0,n-1){
        int u,v, w; cin>>u>>v>>w;
        mp[{min(u,v), max(u,v)}]=w;
    }
       if(n==1){
        cout<<0<<endl;return;
    }
    
    vector<int> dist(n+1, 0);
    dfs(1, 0, dist, n);
    int ct=0;
    for(int i=(1<<(leaf-1)); i<=((1<<leaf)-1); i++){
      v[ct++]=dist[i];
    }

    int maxi=0;

    for(int i=0; i<leaf; i++){
        maxi=max(maxi, v[i]);
    }

    int ans=0;

    for(int i=0; i<leaf; i+=2){
        int x=v[i]; int y=v[i+1];
        if(x==y && x==maxi) continue;
        if(x==y) ans+=1;
        if(x==maxi || y==maxi) ans+=1;
        else ans+=2; 
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