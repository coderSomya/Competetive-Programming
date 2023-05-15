/*
problem link ->
https://codeforces.com/problemset/problem/1738/C
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
  int odd, even;
  odd=even=0;


  for(int i=0; i<n;i++){
    int x; cin>>x;
    odd+=(abs(x)%2);
    even+=(1-abs(x)%2);
  }

  if(odd%4==0){
    cout<<"Alice"<<endl;
  }

  else if(odd%4==1){
    if(even%2){
        cout<<"Alice"<<endl;
    }
    else cout<<"Bob"<<endl;
  }

  else if(odd%4==2){
    cout<<"Bob"<<endl;
  }

  else{
    cout<<"Alice"<<endl;
  }


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}