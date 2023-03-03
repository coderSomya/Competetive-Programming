/*
problem link-
https://codeforces.com/problemset/problem/1776/L
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
   take_n
   string s;
   cin>>s;

   int x=0; int y=0;
   loop(i,0,n){
    x+= s[i]=='+';
    y+= s[i]=='-';
   }

   //b*(x-y) + b*(s-r) +a*(r-s)
   //(x-y)*b - (r-s)*(b-a)

   int q; cin>>q;

   while(q--){
    int a, b; cin>>a>>b;
    // int p=max(a,b); int q=min(a,b);

    int l=-y; int h=x;
    bool flag= true;

    while(l<=h){
   
    int mid= (l+h)/2;
    
    
    int f= (x-y)*b - mid*(b-a);
    
    if(f==0){
        flag= false;
        cout<<"YES"<<endl;
        break;
    }

    else if(f<0) h=mid-1;

    else l=mid+1;

    }

    if(flag) cout<<"NO"<<endl;
   }
}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}