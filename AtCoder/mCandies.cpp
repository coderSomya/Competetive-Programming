/*
problem link ->
https://atcoder.jp/contests/dp/tasks/dp_m
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
   
   int n,k; cin>>n>>k;


   int arr[n+1]; loop(i,1,n+1) cin>>arr[i];
   int dp[n+1][k+1];
   //dp(i,j)= no. of ways to distribute j candies to i people

   //dp(i,j)-> dp(i-1,j)+dp(i-1,j-1)+dp(i-1, j-2)...dp(i-1,j-a[i]);
  memset(dp, 0, sizeof(dp));
  loop(i,0,k+1) dp[1][i]=(i>arr[1])?0:1;

   loop(i,2,n+1){
    loop(j,0,k+1){
        if(j==0) dp[i][j]=dp[i-1][j];
        else{

   dp[i][j]=(mod+dp[i-1][j]-((j-arr[i]>0)?dp[i-1][j-arr[i]-1]:0) + dp[i][j-1])%mod;
        }
          
    }
   }

   cout<<dp[n][k]<<endl;

}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}