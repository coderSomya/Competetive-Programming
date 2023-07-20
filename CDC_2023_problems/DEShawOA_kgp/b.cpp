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
 const int N = 2e5+5;
// #define int long long
// vector<int> v;
int n; 
long long dp[N];
int freq[N];
int rec(int i){
   
   if(i>n) return 0;

   if(dp[i]!=-1) return dp[i];
      long long l = freq[i]*i;
   return dp[i] = max(l + rec(i+2) , (long long) rec(i+1));

}
int getMaxScore(vector<int> arr) {


memset(dp, -1, sizeof(dp));

memset(freq, 0, sizeof(freq));


int maxi =-1;
n= arr.size();
for(int i=0; i<n; i++)
{
    freq[arr[i]]++;
    maxi=max(maxi, arr[i]);
}

n=maxi;
int mod= 1e9+7;
int ans=rec(1);
return ans%mod;
}
 
void solve(){
   vector<int> v {19, 1,2, 4, 8};

   cout<<getMaxScore(v)<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}