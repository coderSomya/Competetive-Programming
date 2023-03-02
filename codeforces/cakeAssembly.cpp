/*
https://codeforces.com/problemset/problem/1786/B
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

int n,h,w;
int a[200000],b[200000];

bool shift(){

    // cout<<"here"<<endl;
   // x ranges from (a0+b0)-(h+w) se (a0+b0)+(h+w)

   int l= b[0]-a[0]+h-w;
   int r= b[0]-a[0]-h+w;

   bool ans=false;

   while(l<r){
    bool flag=true;
    int mid=(l+h)/2;
    // cout<<mid<<endl;
    
    loop(i,0,n){
        if(a[i]+mid+w>=b[i]+h && a[i]+mid-w<=b[i]-h){
            continue;
        }
        else if(a[i]+mid+w<b[i]+h){
            flag=false;
             l=mid+1;
            break;
        }
        else{
            flag=false;
           r=mid-1;
            break;
        }
    }

    if(flag) return true;

   }
   return false;
}


void solve(){
    
    cin>>n>>w>>h;

    
    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>b[i];

    // sort(a,a+n);
    // sort(b,b+n);

     //lets shift them x units right

     //a0+w+x = b0-h
     //a0-w+x= b0+h

     bool x= shift();

     cout<<((x) ? "YES" : "NO")<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}