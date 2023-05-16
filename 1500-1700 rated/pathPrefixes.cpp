/*
problem  link->
https://codeforces.com/problemset/problem/1714/G
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

vector<int> vb;
int curb;
int cura;
vector<int> a;
vector<int> b;
vector<int> ans;
vector<vector<int>> adj;

void dfs(int src){
    curb+=b[src];
    cura+=a[src];
    vb.push_back(curb);
    ans[src]= upper_bound(vb.begin(), vb.end(), cura)-vb.begin();

    for(int x: adj[src])
    {
        dfs(x);
    }

    curb-=b[src];
    cura-=a[src];

    vb.pop_back();
}
 
 
void solve(){
    int n; cin>>n;
    adj.clear();
    a.clear();
    b.clear();
    adj.resize(n+1);
    a.resize(n+1);
    b.resize(n+1);
    ans.clear();
    ans.resize(n+1);

    for(int i=2; i<=n; i++){
     int pr,ai,bi;
     cin>>pr>>ai>>bi;

     adj[pr].push_back(i);
     a[i]=ai;
     b[i]=bi;
    }


    dfs(1);

    for(int i=2; i<=n; i++) cout<<ans[i]-1<<" ";
    cout<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}