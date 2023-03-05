/*
problem link->
https://codeforces.com/contest/1794/problem/C
*/

//O(n*log(n))

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
    int arr[n+1];
    loop(i,1,n+1) cin>>arr[i];

    vi v(n+1,0);
    loop(i,1,n+1){
        //k=i
        
        int l=1; int h=i;
        int ans=1;

        while(l<=h){
          int mid=(l+h)/2;

          if(arr[mid]/(i-mid+1)>=1){
            ans=mid;
            h=mid-1;
          }
          else l=mid+1;
        }

        v[i]=i-ans+1;
    }

    loop(i,1,n+1) cout<<v[i]<<" ";
    cout<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}