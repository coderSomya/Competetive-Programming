/*
problem link ->
https://codeforces.com/problemset/problem/1692/G
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
#define p_arr(A,n)      loop(i,0,n) cout<<A[i]<<" "; cout<<endl;
#define pln_arr(A,n)    loop(i,0,n) cout<<A[i]<<endl
#define take_n          int n; cin>>n;
#define take_arr        int arr[n]; loop(i,0,n) cin>>arr[i];
  
  
const int mod= 1e9+7;
const int inf= 1e15;
 
 
void solve(){
    int n,k;
    cin>>n>>k;
    take_arr

    vi v; 
    loop(i,1,n){
    if(2*arr[i]-arr[i-1]<=0) v.pb(i);
    }
    int ans=0; false;
    int s=v.size();
    if(s==0) {
        ans= n-k;
        cout<<ans<<endl;
        return;
    }

  ans+= max(v[0]-k,(int)0);
  
  //1 7
  loop(i,1,s){
    ans+=max(v[i]-v[i-1]-k, (int)0);
  }

  ans+=max((int)0, n-v[s-1]-k);

  cout<<ans<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}
