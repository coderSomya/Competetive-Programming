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

int dp[2005][2005];
int arr[2005];

int res(int l, int r){
  
  if(l==r) return 0;

  if(dp[l][r]!=-1) return dp[l][r];

  return dp[l][r]= (arr[r]-arr[l]+min(res(l+1,r), res(l,r-1)));
}
 
 
void solve(){

    int n; cin>>n;
    memset(dp,-1,sizeof(dp));
    loop(i,0,n) cin>>arr[i];
   sort(arr,arr+n);
    int ans=res(0,n-1);

    cout<<ans<<endl;
}
  
  
int32_t main(){
solve();
return 0;
}