/*
problem link ->
https://codeforces.com/problemset/problem/1737/C
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

bool parity(int a, int b){
   return a%2==b%2;
}
 
 
void solve(){

    int n; cin>>n;

    int r1,c1,r2,c2,r3,c3;
    cin>>r1>>c1>>r2>>c2>>r3>>c3;

    int x,y; cin>>x>>y;


    int r,c;
    if(r1==r2 || r1==r3) r=r1;
    else r=r2;

    if(c1==c2 || c1==c3) c=c1;
    else c=c2;

    if(r==x || c==y){
        cout<<"YES"<<endl;
        return;
    }

    if((r==1 && c==1)|| (r==n && c==n)){
        cout<<"NO"<<endl;
        return;
    }

   

   if(!parity(x,r) && !parity(y,c)) cout<<"NO"<<endl;

   else cout<<"YES"<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}