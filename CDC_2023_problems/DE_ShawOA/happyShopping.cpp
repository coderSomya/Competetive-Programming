/*
https://www.desiqna.in/15099/shaw-super-hard-dynamic-programming-solution-kumar-2023-may
*/

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

const int N = 1001;

int n;
vector<int> mnq(N);
vector<int> mxq(N);
vector<int> hp(N);
vector<int> cost(N);

int dp[N][N];

int rec(int i, int sum) {
    if(sum<=0) return 0;
    if(i==n) return 0;
   int temp=0;

   if(dp[i][sum]!=-1) return dp[i][sum];

    for(int num=mnq[i]; num<=mxq[i]; num++){
        if(sum - num*cost[i] <0) break;
          temp = max(temp, hp[i]*num+ rec(i+1, sum-num*cost[i]));
    }

    return dp[i][sum] = temp;
}
 
void solve(){

    cin>>n;
    for(int i=0; i<n; i++) cin>>mnq[i];
    for(int i=0; i<n; i++) cin>>mxq[i];
    for(int i=0; i<n; i++) cin>>hp[i];
    for(int i=0; i<n; i++) cin>>cost[i];
    int m ; cin>>m;

    memset(dp, -1, sizeof(dp));

    int ans= rec(0, m);
    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}