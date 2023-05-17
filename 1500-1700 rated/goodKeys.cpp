/*
problem link ->
https://codeforces.com/problemset/problem/1703/G
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

 int n,k;

 vector<vector<int>>dp;

int rec(int i, int level, const vector<vector<int>> &a)
{   

    if(i==n) return 0;
    
    if(level>=30) return 0;

    if(dp[i][level]!=-1) return dp[i][level];
    //good key or bad key
    return dp[i][level]=  max(-k+a[i][level]+rec(i+1,level,a),a[i][level]/2+rec(i+1,level+1,a)) ;
}
 
 
void solve(){
    cin>>n>>k;
    vector<vector<int>> arr(n,vector<int>(31));
    for(int i=0; i<n; i++) cin>>arr[i][0];

    
    dp.clear();
    dp.resize(n, vector<int>(31, -1));

    //wrong approach

    // int dp[n][2];
    // dp[n-1][0]=arr[n-1]/2;
    // dp[n-1][1]=-k + arr[n-1];

    // for(int i=n-2; i>=0; i--){
    //     dp[i][0]=arr[i]/2+max(dp[i+1][0], dp[i+1][1])/2;
    //     dp[i][1]=arr[i]-k+max(dp[i+1][0],dp[i+1][1]);
    // }
    
    for(int level=1; level<31; level++){
        for(int i=0;i<n; i++){
            arr[i][level]=arr[i][level-1]/2;
        }
    }

    cout<<rec(0,0,arr)<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}