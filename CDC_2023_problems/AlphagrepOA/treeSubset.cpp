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

const int N = 2e5;
 

int dp[N][2];
vector<vector<int>> adj(N+1);
vector<int> wt(N+1);

int dfs(int src, int par, int tight){
    int temp=0;

    if(dp[src][tight]!=-1) return dp[src][tight];

    for(auto x: adj[src]){
        if(x!=par) temp+=dfs(x, src, 0);
    }

    int temp2=0;

    if(tight==0){
        
        temp2+=wt[src];

        for(auto x: adj[src]){
            if(x!=par){
                temp2+= dfs(x, src, 1);
            }
        }
    }

    return dp[src][tight]=  max(temp, temp2);
}
 
void solve(){

    memset(dp, -1, sizeof(dp));

    int n; cin>>n;
    adj.clear();
    adj.resize(n+1);
    wt.clear();
    wt.resize(n+1);

   int tf[n-1];

    for(int i=0; i<n-1; i++){
         cin>>tf[i];
    }
     int tt[n-1];

    for(int i=0; i<n-1; i++){
         cin>>tt[i];
    }

loop(i,0,n) cin>>wt[i+1];

loop(i,0,n-1){
    adj[tf[i]].push_back(tt[i]);
}

int ans=dfs(1, 0, 0);

cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}