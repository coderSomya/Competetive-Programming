/*
problem link->
https://codeforces.com/problemset/problem/1659/C
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
 
 
void solve(){
    int n,a,b;
    cin>>n>>a>>b;

    vi v; 
    v.pb(0);
    loop(i,0,n){
        int x; cin>>x;
        v.pb(x);
    }

  
    int pref[n+1];
    int suff[n+1];
    int predif[n+1];
    
    pref[0]=v[0];
    loop(i,0,n){
        pref[i+1]=pref[i]+v[i+1];
    }
    suff[n]=v[n];
    for(int i=n-1; i>=0; i--){
        suff[i]=suff[i+1]+v[i];
    }

    loop(i,1,n+1){
        predif[i]=v[i]-v[i-1];
    }
    int ans =b*suff[0];
    loop(i,1,n+1){
       ans=min(ans, (a+b)*v[i] + b*(pref[n]-pref[i] -(n-i)*v[i]));
    }

    cout<<ans<<endl;

    
   
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}