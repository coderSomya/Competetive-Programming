/*
problem link ->
https://codeforces.com/problemset/problem/1659/B
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
#define p_arr(A,n)      loop(i,0,n) cout<<A[i]<<" "; cout<<endl;
#define pln_arr(A,n)    loop(i,0,n) cout<<A[i]<<endl
#define take_n          int n; cin>>n;
#define take_arr        int arr[n]; loop(i,0,n) cin>>arr[i];
  
  
const int mod= 1e9+7;
const int inf= 1e15;
 
 
void solve(){
    int n,k;
    cin>>n>>k;

    string s; cin>>s;
    int arr[n]={0}; int ct=0;

    loop(i,0,n){

        if(ct==k) break;
          if(s[i]=='1'){
            arr[i]= k%2;
            ct+= arr[i];
          }
          else{
            arr[i]= 1- k%2;
             ct+= arr[i];
          }
    }

    string ans="";
    if(ct<k) arr[n-1]+=k-ct;

    loop(i,0,n){
        if((k-arr[i])%2 ==0){
            ans+= s[i];
        }
        else{
         if(s[i]=='1') ans+='0';
         else ans+= '1';
        }
    }

    cout<<ans<<endl;
    p_arr(arr,n)
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}