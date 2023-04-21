/*
problem link ->
https://atcoder.jp/contests/dp/tasks/dp_n
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

    take_n
    take_arr

    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    //dp(i,j) stores min cost to combine i..j

    

    int pref[n]; pref[0]=arr[0];
    loop(i,1,n) pref[i]=pref[i-1]+arr[i];

    for(int width=2; width<=n; width++){
        for(int i=0; i<=n-width; i++){
          int j=i+width-1;
          int temp=inf;
          for(int k=0; k<=j-i-1; k++){
            temp=min(temp, dp[i][i+k]+dp[i+k+1][j]+ pref[j]-pref[i]+arr[i]);
          }
          dp[i][j]=temp;
        }
    }

    cout<<dp[0][n-1]<<endl;

}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}