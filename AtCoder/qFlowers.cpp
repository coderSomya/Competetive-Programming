/*
problem link -
https://atcoder.jp/contests/dp/tasks/dp_q
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
    int height[n], beauty[n];
    loop(i,0,n) cin>>height[i];
    loop(i,0,n) cin>>beauty[i];

    int dp[n];
    dp[0]=beauty[0];
    //dp(i)-> max beauty if i is the last index we pick

    //dp(i)-> beauty(i), check for all hj <hi && j<i dp(j)+beauty(i)

    //will continue with this one
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}