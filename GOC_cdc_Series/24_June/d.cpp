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
 
int size;
set<int> enem;
bool flag;
void dfs(int src, int par, vector<int> &vis, vector<vector<int>> &adj){
    vis[src]=1;
    size++;
    if(enem.find(src)!=enem.end()) flag=true;
    for(auto x: adj[src]){
       if(!vis[x]) dfs(x,src, vis, adj);
    }
}
 
void solve(){
    int n,m; cin>>n>>m;
    vector<vector<int>>adj(n+1);

    loop(i,0,m){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int k; cin>>k;
    loop(i,0,k){
        int r; cin>>r; enem.insert(r);
    }
  vector<int> vis(n+1,0);
  vector<int> safe;
  vector<int> rem;
  int cc=0; int ans=0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            size=0;
            flag=false;
            cc++;
            dfs(i, -1, vis, adj);
            if(flag) safe.pb(size);
            else rem.pb(size);
        }
    }

    
   //options:

   /*
   2, 5, 6, 7
   5, 6, 3
   
   1 1 1 1 1 1 1 1 1 2
   5 6 7
   20c2+ ..
   18c2+ 1+ 3
   */

int opt1, opt2;
opt1=opt2=0;
     sort(safe.rbegin(), safe.rend());
     for(int i=1; i<k; i++){
      opt1+= safe[i]*(safe[i]-1)/2;
     }

     int total=0;
     for(auto x: rem) total+=x;
     total+=safe[0];
     opt1+=total*(total-1)/2;


     //option2
     int tot=0;
     for(auto x: rem) tot+=x;
     opt2+=tot*(tot-1)/2;
    
     for(int i=0; i<k; i++) {
        opt2+= safe[i]*(safe[i]-1)/2;
     }
    
    opt2+=min((int)rem.size(), k);

//  cout<<opt1<<" "<<opt2<<endl;
    ans=max(opt1,opt2);

    cout<<ans-m<<endl;


}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}