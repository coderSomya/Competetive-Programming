/*
problem link ->
https://atcoder.jp/contests/dp/tasks/dp_p
*/


//dp on trees


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

int dp[100006][2];


vector<vector<int>> adj; 

int ways(int root, int x, int par){   

    // if(adj[root].size()==1){
    //     if(x==0) return 2;
    //     else return 1;
    // }

    if(dp[root][x]!=-1) return dp[root][x];

    int ans=0;
    int temp=1;
    for(auto child: adj[root]){
       if(child!=par) temp= (temp*(ways(child,0, root))%mod)%mod;
    }
    ans=(ans+temp)%mod;
    temp=1;
    if(x==0){
        for(auto child: adj[root]){
           if(child!=par) temp=(temp*(ways(child,1, root))%mod)%mod;
        }

        ans=(ans+temp)%mod;
    }
    

    return dp[root][x]=ans;
}
 
void solve(){
    take_n
    adj.clear();
    adj.resize(n+1);
    loop(i,0,n-1){
        int x,y; cin>>x>>y;
       
        adj[x].pb(y);
        adj[y].pb(x);
    }

    memset(dp,-1, sizeof(dp));

    //dp(u,0)-> u is under no constraint
    //dp(u,1)-> u can only be painted white

    //dp(u,0)= product of dp(child,0)+ product of dp(child,1)
    //dp(u,1)= product of dp(child,0)

    //root the tree first
   int ans=ways(1,0,-1);
   cout<<ans<<endl;


}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--)
 solve();
return 0;
}