/*
problem link ->
https://codeforces.com/problemset/problem/1733/D1
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

   int n,x,y; cin>>n>>x>>y;
   string a,b;
   cin>>a>>b;

   int l=0,h=n-1;
   int ct=0;
   loop(i,0,n) ct+=a[i]!=b[i];
   if(ct%2){
    cout<<-1<<endl; return;
   }
    
    else if(ct==2){
       vi v;
       loop(i,0,n) if(a[i]!=b[i]) v.pb(i);
       if(v[1]-v[0]==1){
         int ans= min(2*y,x);
         cout<<ans<<endl;
       }
       else  cout<<y<<endl;
    }
    else{
       int ans= ct/2*y;
       
    }



}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}