/*
problem link ->
https://codeforces.com/problemset/problem/1569/C
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
  
  
const int mod= 998244353;
const int inf= 1e15;

int fact[200005];
 
 
void solve(){
    int n; cin>>n;
    take_arr

    sort(arr, arr+n);

    int maxi=arr[n-1]; int smaxi=-1;
    for(int i=n-2; i>=0; i--){
        if(arr[i]!=maxi){
            smaxi=arr[i];
            break;
        }
    }
    int a=0; int b=0;
    loop(i,0,n){
      a+=arr[i]==maxi;
      b+= arr[i]==smaxi;
    }

    if(a>1){
        cout<<fact[n]<<endl;
        return;
    }
    
    if(maxi-smaxi >1){
        cout<<0<<endl; return;
    }
    
    int ans= b*fact[n]/(b+1);
    
}
  
  
int32_t main(){
fact[0]=1;
loop(i,1,200005){
  fact[i]=(fact[i-1]*i)%mod;
}
int t;
cin>>t;
while(t--) solve();
return 0;
}