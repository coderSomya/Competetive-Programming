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
 
//n== odd hai to 0 ties
//n== even hai to n/2 ties

//circle apporoach

void solve_even(int n){
   int dp[n+1][n+1];
   memset(dp,0,sizeof(dp));
   //ties
   int gap=(n-2)/2;
   int complement=1+gap;
   for(int i=1; i<n/2; i++)
   {
    dp[i][i+complement]=0;
    dp[i+complement][i]=0;
   }

   for(int i=1; i<=n; i++){
     for(int j=1; j<=gap; j++){
        dp[i][(i+j)<=n? (i+j): (i+j)-n]=1;
     }
     for(int j=1; j<=gap; j++){
        dp[i][(i-j)>0?(i-j): n+(i-j)]=-1;
     }
   }

   for(int i=1; i<=n; i++){
    for(int j=i+1; j<=n; j++) cout<<dp[i][j]<<" ";
   }

   cout<<endl;
}

void solve_odd(int n){
  
  //no ties
  int forward=(n-1)/2;
  int dp[n+1][n+1];
  memset(dp, 0, sizeof(dp));
  for(int i=1; i<=n; i++){
     
     for(int j=1; j<=forward; j++){
        dp[i][(i+j)<=n? i+j: (i+j-n)]=1;
     }

     for(int j=1; j<=forward; j++){
        dp[i][(i-j)>0?(i-j):(i-j+n)]=-1;
     }
  }

  for(int i=1; i<=n; i++){
    for(int j=i+1; j<=n; j++) cout<<dp[i][j]<<" ";
  }

  cout<<endl;

}


void solve(){

    take_n
    if(n%2){
      solve_odd(n);
    }
    else{
     solve_even(n);
    }

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}