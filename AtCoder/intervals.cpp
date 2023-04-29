/*
problem link ->
https://atcoder.jp/contests/dp/tasks/dp_w
*/

//O(n^2) approach

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
    
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>>v(n);
    //v(i) stores all intervals starting at i, with their end points and scores
    
    loop(i,0,m){
        int l,r,x; 
       cin>>l>>r>>x;
        l--; r--; 
        v[l].pb({r,x});
    }

    int dp[n];
    memset(dp, 0, sizeof(dp));
    for(auto x: v[0]) dp[0]+=x.second;

    int ans=max((int)0, dp[0]);

    for(int i=1; i<n; i++){ 
        for(int j=i; j>0; j--){
            int temp=0;
            for(auto x: v[j]){
                if(x.first>=i){
                   temp+=x.second;
                } 
            }
            dp[i]=max(dp[i], temp+dp[j-1]);
            ans=max(ans, dp[i]);
        }
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}