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

    if(n>=3){
     cout<<2<<" ";

     int y=4;
     int x=n-3; 
     int a,b;
     if(x%2==0){
       a=b=x/2;
     }
     else{
        a=x/2;
        b=x/2+1;
     }

     for(int i=0; i<a; i++) cout<<y++<<" ";
     cout<<1<<" ";
     for(int i=0; i<b; i++) cout<<y++<<" ";
     cout<<3<<endl;
     return; 
    }

    if(n==1) cout<<1<<endl;

    else if(n==2) cout<<2<<" "<<1<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}