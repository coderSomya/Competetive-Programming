/*
problem link ->
https://codeforces.com/problemset/problem/1675/E
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

    int n,k; cin>>n>>k;

    string s; cin>>s;
    string ans;
    
    int maxi=0; int l=0;
    loop(i,0,n){
        if(s[i]-'a'<=k) maxi=max(maxi, (long long)(s[i]-'0'));
        else{
            for(int j=l; j<i; j++) ans+='a';
            k-=
        }
        

    }
  

    loop(i,0,n){
     
    }


    
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}