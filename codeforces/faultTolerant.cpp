/*
problem link ->
https://codeforces.com/problemset/problem/1651/C
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

    int n; cin>>n; 
    int a[n],b[n];
    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>b[i];
    
    int u=abs(a[0]-b[0]);
    int v=abs(a[n-1]-b[n-1]);
    int x=abs(a[0]-b[n-1]);
    int y=abs(a[n-1]-b[0]);

    int afmin=inf; int almin=inf;
    int bfmin=inf; int blmin=inf;


    loop(i,0,n){
        afmin=min(afmin, abs(a[0]-b[i]));
        almin=min(almin, abs(a[n-1]-b[i]));
        bfmin=min(bfmin, abs(b[0]-a[i]));
        blmin=min(blmin, abs(b[n-1]-a[i]));
    }

    int ans= min(u+v, x+y);
    ans=min(ans, u+ almin+blmin );
    ans=min(ans, v+ afmin+bfmin );

    ans=min(ans, x+almin+ bfmin);
    ans=min(ans, y+afmin+ blmin);

    ans= min(ans, afmin+almin+bfmin+blmin);

    cout<<ans<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}