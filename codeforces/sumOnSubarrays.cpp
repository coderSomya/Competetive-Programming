/*
problem link ->
https://codeforces.com/problemset/problem/1809/C
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

void pos(int n, int k){
    int m=k;
    vi v;
  while(m>0){
    int x=1;
    while(x*(x+1)/2<=m) x++;
    x--;
    m-=x*(x+1)/2;
    v.pb(x);
  }

//   loop(i,0,v.size()) cout<<v[i]<<" ";

  for(int i=0; i<v.size(); i++){
    for(int j=1;j<v[i]+1; j++){
        cout<<j<<" ";
    }
    n-=v[i];
    if(n) {
        cout<<-1000<<" "; n--;}
  }

  while(n){
    cout<<-1000<<" ";
    n--;
  }

  cout<<endl;
  
}

void neg(int n, int k){
        int m=k;
    vi v;
  while(m>0){
    int x=1;
    while(x*(x+1)/2<=m) x++;
    x--;
    m-=x*(x+1)/2;
    v.pb(x);
  }

//   loop(i,0,v.size()) cout<<v[i]<<" ";

  for(int i=0; i<v.size(); i++){
    for(int j=1;j<v[i]+1; j++){
        cout<<-j<<" ";
    }
    n-=v[i];
    if(n) {
        cout<<1000<<" "; n--;}
  }

  while(n){
    cout<<1000<<" ";
    n--;
  }

  cout<<endl;
  
}


 
 
void solve(){
    int n,k;
    cin>>n>>k;

    if(k<n*(n+1)/2-k){
        //pos se start
        pos(n,k);
    }
    else{
        neg(n,n*(n+1)/2-k);
    }
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}