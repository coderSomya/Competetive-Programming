/*
problem link->
https://codeforces.com/problemset/problem/1475/E
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

const int N = 1000;

int fact[N+1], invfact[N+1];

int binexpo(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;

    int res=binexpo(a,b/2);
    res=(res*res)%mod;

    if(b%2) res=(res*a)%mod;

    return res;

}
 
int ncr(int n, int r){
    if(r>n) return 0;

    return ((fact[n]*invfact[r]%mod)*invfact[n-r])%mod;

}
void solve(){
    int n,k; cin>>n>>k;

    take_arr
    sort(arr, arr+n);
    reverse(arr,arr+n);
    int elem=arr[k-1];
    int last=n;
    for(int i=k; i<n; i++){
         if(arr[i]!=elem){
            last=i;
            break;
         }
    }

    int curr=0;
    for(int i=0; i<n; i++) curr+=(arr[i]==elem);

    int taken=0;
     
    for(int i=0; i<n; i++){
        if(arr[i]==elem){
            taken=i;
            break;
        }
    }
    int ans= ncr(curr, k-taken);

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;

fact[0]=1;
loop(i,1,N+1) fact[i]=(fact[i-1]*i)%mod;

invfact[N]=binexpo(fact[N], mod-2);
for(int i=N-1; i>=0; i--){
    invfact[i]=(invfact[i+1]*(i+1))%mod;
}
while(t--) solve();
return 0;
}