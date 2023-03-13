/*
problem link ->
https://codeforces.com/problemset/problem/1644/C
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

vi arr(5001); int n;

int solve2(int len){
    //generates maximum sum subarray of length=i
    //sliding window

    int ans=0;
    int low=0;
    int high=0;
    while(high<len){
     ans+=arr[high]; high++;
    }

    int res=ans;
    while(high<n){
        ans+=arr[high];
        ans-=arr[low];
        low++; high++;
        res=max(res, ans);
    }

    return res;


}


 
void solve(){

    int x;
    cin>>n>>x;
    arr.clear(); arr.resize(n);
    loop(i,0,n) cin>>arr[i];

    vi len(n+1);
    loop(i,0,n+1){
        len[i]=solve2(i);
    }

    // we have max sum subarray for each length

    vector<vector<int>> v(n+1,vector<int>(n+1,0));

    loop(i,0,n+1){
        loop(j,0,n+1){
            v[i][j]=len[i]+ x*min(i,j);
        }
    }
  
//   loop(i,0,n+1)
//         loop(j,0,n+1) cout<<i<<" "<<j<<" "<<v[i][j]<<endl;

   vi ans;
   loop(ks,0,n+1){
    int temp=-1;
     for(int i=0; i<=n; i++) temp=max(temp, v[i][ks]);
     ans.pb(temp);
   }

   loop(i,0,n+1) cout<<ans[i]<<" ";
   cout<<endl;

    
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}