/*
problem link->
https://codeforces.com/problemset/problem/1473/C
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
    int n,k;
    cin>>n>>k;

    int l=0; int h=k;
    int ans=k;
    int x=(n-k)*(n-k);
    //minimize ans;
    while(l<=h){
        int mid=(l+h)/2;
        
        if((k-mid)*(k-mid-1)/2 <=x){
            ans=mid; h=mid-1;
        }
        else l=mid+1;
    }

    for(int i=1; i<=ans; i++) cout<<i<<" ";
    for(int i=1; i<=k-ans; i++) cout<<k-i+1<<" ";


    cout<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}