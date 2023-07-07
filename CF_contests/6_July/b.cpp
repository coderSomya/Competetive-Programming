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


#define debug(...) cout<<'[ '<<#__VA_ARGS__ <<':'<<(__VA_ARGS__)<<' ]'<<endl;
 
 
void solve(){
    take_n
    take_arr

    int res=arr[0];

    for(int i=1; i<n; i++){
        res=res&arr[i];
    }
   if(res!=0){
    cout<<1<<endl;
    return;
   }
    int ct=0;
    int curr=1ll*(1<<31)-1;
    for(int i=0;i<n; i++){
        curr=curr&arr[i];
        if(curr==0){
            ct++;
            curr=(1ll*(1<<31)-1);
        }
        else{
            curr=(curr&arr[i]);
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