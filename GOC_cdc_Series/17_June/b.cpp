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

    vector<int> arr(n);
    loop(i,0,n) cin>>arr[i];
    vector<int> v(arr);
    sort(v.begin(), v.end());
    umpii mp;
    umpii freq;
    mp[v[0]]=1;
    freq[1]=1;
    for(int i=1; i<n; i++){
     if(v[i]==v[i-1]) freq[mp[v[i]]]++;
     else{
        mp[v[i]]=mp[v[i-1]]+1;
        freq[mp[v[i]]]=freq[mp[v[i-1]]]+1;
     }
    }





    int maxi=0;
  int ct=0; int mxct=0;
    for(int i=0; i<n; i++){
        int r=mp[arr[i]];
     
        if(r>maxi){
            maxi=r;
            mxct=1;
        }
        else if(r==maxi){
            mxct++;
        }

        if(maxi==1){
            ct++;
            continue;
        }
        if(i+1-mxct == freq[maxi-1]){
            ct++;
        }
    }

    cout<<ct<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}