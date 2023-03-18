/*
problem link ->
https://codeforces.com/problemset/problem/1609/C
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
  
const int N=(int)1e6+1;  
const int mod= 1e9+7;
const int inf= 1e15;
 
bool prime[N];

void solve(){

    int n,e; cin>>n>>e;
    int ans=0;
    vi v(n); loop(i,0,n) cin>>v[i];
    loop(i,0,n) if(prime[v[i]]){
        //go left to max e steps
        //go right to max e steps
        //till you have ones only
        int left=0;
        int j=i-e;
        while(j>=0 && v[j]==1){
            left++; j-=e;
        }
        int right=0;
        int k=i+e;
        while(k<n && v[k]==1){
            right++; k+=e;
        }
        ans+=(left+1)*(right+1)-1;
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
    

    memset(prime,true,sizeof(prime)); prime[0]=false; prime[1]=false;
 
    for (int p=2; p*p<N; p++) {
        if (prime[p]) {
             for (int i=p*p; i<N; i+=p) prime[i] = false;
        }
    }


 
int t;
cin>>t;
while(t--) solve();
return 0;
}