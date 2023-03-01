/*
problem link -
https://atcoder.jp/contests/dp/tasks/dp_i
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
 
 
void solve(){
    int n; cin>>n; 
    double arr[n+1];
    loop(i,0,n) cin>>arr[i+1];

    double dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    //dp(i,j)-> probability we are at i, and have chosen j heads
    //dp(i,j)=dp(i-1,j)*(1-arr[i])+dp(i-1, j-1)*arr[i]

    double pref[n+1];
    pref[0]=double(1);

    loop(i,1,n+1) pref[i]=pref[i-1]*(1-arr[i]);
  
    loop(i,1,n+1){
        dp[1][i]=0;
    }
    dp[1][1]=arr[1];

    loop(i,2,n+1) dp[i][1]=dp[i-1][1]*(1-arr[i]) + pref[i-1]*arr[i];

    for(int i=2; i<=n; i++){
        for(int j=2; j<=i; j++){
            dp[i][j]= dp[i-1][j]*(1-arr[i])+ dp[i-1][j-1]*arr[i];
        }
    }

    double ans=0;

    // loop(i,1,n+1) {
    //     loop(j,1,n+1) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }

    loop(i,(n+1)/2, n+1){
        ans+= dp[n][i];
    }
    cout<<setprecision(15)<<endl;
    cout<<ans<<endl;
}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}