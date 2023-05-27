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
  int l[5001], r[5001];

// vector<vector<int>> dp(5001, vector<int>(5001));
int dp[5001][5001][2];
 
bool check(int i, int sum, int n){

    // cout<<i<<" "<<sum<<endl;

    if(sum<0) return false;

    if(dp[i][sum][0]!=-1) return dp[i][sum][0];
    if(dp[i][sum][1]!=-1) return dp[i][sum][0];

    if(i==n-1){
        if(sum-l[n-1]==0){
            return dp[i][sum][0]=true;
        }
        else if(sum-r[i]==0){
            return dp[i][sum][1]=true;
        }
        else return dp[i][sum][0]=dp[i][sum][1]=false;
    }
    

    if(check(i+1, sum-l[i], n)) {
      return dp[i][sum][0]=true;
    }
    else if(check(i+1, sum-r[i], n)) {
      return dp[i][sum][1]=true;
    }
    else return dp[i][sum][0]=dp[i][sum][1]=false;
    

    // return check(i+1, sum-l[i], n) || check(i+1, sum-r[i], n);

}
 
void solve(){
    int n,m; cin>>n>>m;
    
   memset(dp, -1, sizeof(dp));
  
    for(int i=0; i<n; i++) cin>>l[i];
    for(int i=0; i<n; i++) cin>>r[i];
    string ans="";

   bool res=check(0,m,n);

   cout<<(res? "YES" : "NO")<<endl;
   reverse(ans.begin(), ans.end());
  if(res){
    for(int i=0; i<n; i++){
        if(dp[i][m][0]==1){
            ans+="0";
            m-=l[i];
        }
        else{
            ans+="1";
            m-=r[i];
        }
    }
  }

  if(res) cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}