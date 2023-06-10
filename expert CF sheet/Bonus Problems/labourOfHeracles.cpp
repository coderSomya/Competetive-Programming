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
 
 
void solve(){
    take_n
    int wt[n+1];
    loop(i,1,n+1) cin>>wt[i];

    vector<vector<int>> adj(n+1);
    loop(i,0,n-1){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int ans=0;
    loop(i,1,n+1){
        ans+=wt[i];
    }

    priority_queue<pair<int,int>> pq;
    loop(i,1,n+1){
        int weight=wt[i];
        int size=adj[i].size()-1;
        if(size>0)
        pq.push({weight, size});
    }

  cout<<ans<<" ";
    for(int i=1; i<n-1; i++){
      
        int wt=pq.top().first;
        int sz=pq.top().second;

        pq.pop();
        ans+=wt;
        sz--;
        if(sz>0) pq.push({wt,sz});
        cout<<ans<<" ";
    }

    cout<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}