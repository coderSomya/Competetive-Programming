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
    take_n
    int a[n], b[n];
    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>b[i];

    int pref[n], suff[n];
    pref[0]=a[0]*b[0];
    suff[n-1]=a[n-1]*b[n-1];
    loop(i,1,n) {
        pref[i]=pref[i-1]+a[i]*b[i];
        suff[n-1-i]=suff[n-i]+a[n-1-i]*b[n-1-i];
    }

    int ans=0;

    //odd length
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<n; i++) {
        dp[i][0]=a[i]*b[i];
        dp[i][0]+=(i-1>=0?pref[i-1]:0)+(i+1<n?suff[i+1]:0);
    }

    int maxi=pref[n-1];
    int idx, length;

    //dp(i,len)->  (0...i-len-1)+rev(i-len...i...i+len)+(i+len+1....n-1)

    for(int len=1; len<n; len++){
        for(int i=0; i<n; i++){
            if(i-len>=0 && i+len<n){
               dp[i][len]=dp[i][len-1] +a[i-len]*b[i+len]+a[i+len]*b[i-len];
               dp[i][len]-=(a[i-len]*b[i-len] + b[i+len]*a[i+len]);
              
               maxi=max(maxi, dp[i][len]);
            }
        }
    }

 

    //even length

    memset(dp, 0, sizeof(dp));

    //dp(i,len)-->
    /*
      i-len-1..i+len
    */
     for(int i=0; i<n-1; i++){
        dp[i][0]=pref[n-1];
     }
     for(int len=1;len<n; len++){
        for(int i=0; i<n-1; i++){
            if(i-len+1>=0 && i+len<n)
            {
                dp[i][len]=dp[i][len-1];
                dp[i][len]+=a[i-len+1]*b[i+len] + a[i+len]*b[i-len+1];
                dp[i][len]-=(a[i-len+1]*b[i-len+1]+ b[i+len]*a[i+len]);

                maxi=max(maxi, dp[i][len]);
            }
        }
     }
   
 


    cout<<maxi<<endl;



}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}