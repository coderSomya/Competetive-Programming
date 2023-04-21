/*
problem link->
https://mega.nz/folder/nVUmDazA#nOlJb0eQsAXNxy3B6Ey9lQ/folder/PEt3wZCa
*/

//very good techinque for dp problems

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

int n; 
int dp[22][1<<22];
int c[22][22];



int dpWithBitmasking(int i, int womenSubset){
   
   if(i==n){
    if(womenSubset==0) return 1; return 0;
   }

   if(dp[i][womenSubset]!=-1) return dp[i][womenSubset];

   int ans=0;

   loop(j,0,n){
    if(womenSubset&(1<<j)){
        if(c[i][j]){
            ans=(ans+dpWithBitmasking(i+1, womenSubset^(1<<j))%mod)%mod;
        }
    }
   }
    return dp[i][womenSubset]=ans;
}
 
 
void solve(){

    //dp(i,X)-> no. of ways to make valid pairing of i elements with X being the availability state
    
    cin>>n;
    memset(dp, -1, sizeof(dp));

    loop(i,0,n) loop(j,0,n) cin>>c[i][j];

    int x= dpWithBitmasking(0,((1<<n) -1));

    cout<<x<<endl;

}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--)
solve();
return 0;
}