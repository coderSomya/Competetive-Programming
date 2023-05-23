/*
problem link ->
https://codeforces.com/problemset/problem/1680/C
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
    string s; cin>>s;
    int n=s.length();

    int pref[n]; pref[0]=(s[0]=='0'? 1: -1);
    int suff[n]; suff[n-1]=(s[n-1]=='0'?1:-1);
    for(int i=1; i<n; i++) pref[i]=pref[i-1]+ (s[i]=='0'?1:-1);
    for(int i=n-2; i>=0; i--) suff[i]=suff[i+1]+(s[i]=='0'?1:-1);
    
    vector<int> maxi(n+1);
    maxi[n]=0;
    for(int i=n-1; i>=0; i--)
    maxi[i]=max(maxi[i+1], suff[i]);
    //maximize pref[i]+max over suff[i+1...n-1]

    int ans=-inf;
    int idx=-1;

    for(int i=0; i<n; i++){
       if(pref[i]+maxi[i+1]<ans){
        ans=pref[i]+maxi[i+1];
        idx=i;
       }
    }

    
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}