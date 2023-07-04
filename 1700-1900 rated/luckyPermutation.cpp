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

unordered_set<int> st;
bool flag;
vector<int> vis;
 
void dfs(int src, int par, vector<vector<int>> &adj){

    vis[src]=1;
    if(st.find(src-1)!=st.end() || st.find(src+1)!=st.end()){
        flag=true;
    }
    st.insert(src);
    for(auto x: adj[src]){
        if(x!=par){
            if(vis[x]){
                return;
            }
            dfs(x,src, adj);
        }
    }

}
void solve(){
  vis.clear();
  st.clear();
  int n; cin>>n;
  int arr[n+1];
  loop(i,0,n) cin>>arr[i+1];
  vis.resize(n+1,0);
  flag=false;

  vector<vector<int>> adj(n+1);
  for(int i=1; i<=n; i++){
    adj[i].push_back(arr[i]);
   
    // adj[arr[i]].push_back(i);
  }

  vector<pair<int,int>> sizes;

  for(int i=1; i<=n; i++){
    if(!vis[i]){
        st.clear();
        dfs(i, -1, adj);
        sizes.pb({st.size(), flag});
    }
  }



  int all=0;
  for(auto x: sizes){
    all+= x.first-1;
  }

  if(all==0) all+=1;
  else if(!flag) all++;

  if(flag) all--;
  
  cout<<all<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}