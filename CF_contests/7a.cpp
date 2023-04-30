/*
problem link->
https://codeforces.com/contest/1817/problem/A
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
    int n,q; cin>>n>>q;

    int arr[n];
    loop(i,0,n) cin>>arr[i];

    int pref[n];
    pref[0]=pref[1]=0;
    loop(i,2,n){
        if(arr[i-2]>=arr[i-1] && arr[i-1]>=arr[i]) pref[i]=1+pref[i-1];
        else pref[i]=pref[i-1];
    }

    while(q--){
        int l,r; cin>>l>>r;
        l--; r--;

        int x= pref[r]-(l>0 ?pref[l-1]: 0);
        int ans= r-l+1;
    

        if(r-l+1>2){
            ans-=x;
        }

        cout<<ans<<endl;
    }
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}