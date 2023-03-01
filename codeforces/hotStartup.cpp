
/*
problem link -
https://codeforces.com/problemset/problem/1799/D1
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
vi arr, hot, cold;


//we only need to keep which value other than the last value was used by a cpu
//one of x, y will always be arr[i-1]
int dp[5000][5001];
int rec(int i, int dummy){
    
    
    //base case
   
    if(i==n) return 0;

    if(dp[i][dummy]!=-1) return dp[i][dummy];
    
    //transition
  
    if(arr[i-1]==arr[i]) return dp[i][dummy]= hot[arr[i]]+ rec(i+1, dummy);
    else if(dummy==arr[i]) return dp[i][dummy]= hot[arr[i]]+ rec(i+1, arr[i-1]);

    else return dp[i][dummy]= cold[arr[i]]+ min(rec(i+1, dummy), rec(i+1, arr[i-1]));


   
}
void solve(){
    
    cin>>n>>k;

    arr.clear(); arr.resize(n);
    loop(i,0,n) cin>>arr[i];

    cold.clear();cold.resize(k+1);
    hot.clear();hot.resize(k+1);
    loop(i,1,k+1) cin>>cold[i];
    loop(i,1,k+1) cin>>hot[i];

    memset(dp, -1, sizeof(dp));

    int ans= cold[arr[0]]+ rec(1, 0);
    cout<<ans<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}