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
   string s; cin>>s;
   int n=s.length();

   int dp[n][n];
   for(int i=0; i<n; i++){
      dp[i][i]=1;
   }

   for(int i=0;i<n; i++) for(int j=0; j<n; j++) if(j<i) dp[i][j]=0;

   for(int len=1; len<n; len++){
     for(int i=0;i+len<n; i++){
        int j=i+len;
        if(s[i]==s[j]) dp[i][j]=2+dp[i+1][j-1];
        else dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
     }
   }

   vector<int>as;
   vector<int>gs;
   for(int i=0; i<n; i++){
   if(s[i]=='A') as.pb(i);
   if(s[i]=='G') gs.pb(i);
   }

   int amax,gmax;
   amax=gmax=0;

   for(int i=0;i<as.size(); i++){
for(int j=0; j<as.size(); j++) amax=max(amax, dp[as[i]][as[j]]);
   }

   for(int i=0; i<gs.size(); i++) for(int j=0; j<gs.size(); j++){
    gmax=max(gmax, dp[gs[i]][gs[j]]);
   }
   

   cout<<amax<<" "<<gmax<<endl;
}
    


  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}