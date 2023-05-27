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
unordered_map<int,set<int>>mp;
   int arr[21];
   int dp[21][1<<21];

int freq=0;
int find(int pos, int mask){
//cout<<mask<<endl;


  if(pos==n) return 0;

  if(dp[pos][mask]!=-1) return dp[pos][mask];
  int temp=-inf;
  for(int i=0; i<2*k; i++){
    if(mask&(1<<i)){
        int x=(i+1>k)?(i+1-k):i+1;
        int temp_mask=mask^(1<<i);
        temp=max(temp, (arr[pos] & x) + find(pos+1, temp_mask));
    }
  }

  return dp[pos][mask]=temp;
  
}
 
void solve(){

  cin>>n>>k;

   for(int i=0; i<n; i++){
    cin>>arr[i];
   }

   memset(dp, -1, sizeof(dp));
  int res=find(0,(1<<(2*k))-1);
  cout<<res<<endl;


}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}