/*
problem link ->
https://codeforces.com/problemset/problem/1553/D
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

int n,m;
string s,t;

int func(int i, int j){
  if(i<j){
     return 0;
  }
  if(j<0) return 1;
  if(i==0) return s[i]==t[j];
  if(s[i]==t[j]){
    return func(i-1,j-1) || func(i-2,j);
  }
  else return func(i-2,j);
}


void solve(){
   
    cin>>s>>t;
    n=s.length();
    m=t.length();

   

    if(func(n-1,m-1)){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
    // if(m>n){
    //     cout<<"NO"<<endl;
    //     return;
    // }
    // int i=n-1; int j=m-1; bool flag=false;
    // while(i>=0){
    //     if(j<0) {
    //         flag=true;
    //         cout<<"YES"<<endl; return;
    //     }
    //     if(s[i]==t[j]){
    //         i--; j--;
    //     }
    //     else {
    //         i-=2;
    //     }
    // }


    // if(!flag) cout<<"NO"<<endl;
    

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}