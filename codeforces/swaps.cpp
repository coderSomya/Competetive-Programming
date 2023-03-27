/*
problem link ->
https://codeforces.com/problemset/problem/1573/B
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
    take_n
    int a[n],b[n];
    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>b[i];
    int mini[n]; mini[0]=a[0];
    loop(i,1,n){
        mini[i]=min(mini[i-1], a[i]);
    }
    int i=n-1; int j=0; int ans=inf;
    while(i>=0 && j<n){
      while(i>=0 && mini[i]<b[j]) i--; i++;
      ans=min(ans, i+j);
      j++;
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}