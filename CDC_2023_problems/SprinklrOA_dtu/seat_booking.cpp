#include <bits/stdc++.h>
using namespace std;
#define loop(i,l,r)     for(int i=l; i<r; i++)
#define int             long long
#define pb              push_back
#define vi              vector<int>
#define mkp             make_pair<int,int>
#define umpii           unordered_map<int,int>
/*
https://www.thejoboverflow.com/p/p1333/
*/



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

const int N = 502; 
const int M = 13;
int dp[N][(1<<M)];

int A[N];
int B[N];

int n,m;

int rec(int i, int mask){
   
   if(mask==(1<<(m-1))) return 0;

   if(i>=n) return -inf;

   if(dp[i][mask]!=-1) return dp[i][mask];

   int temp=rec(i+1, mask);

   for(int bit=0; bit<13; bit++){
    if(mask&(1<<bit)){
        int temp_mask= mask|(1<<bit);
        if(i+B[i]-1>n) continue;
        temp=max(temp, A[i+B[i]-1] - (i?A[i-1]:0) + rec(i+B[i], temp_mask));
    }
   }

   return dp[i][mask]=temp;
}
 
 
void solve(){
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}