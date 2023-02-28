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
    string s; cin>>s;
    // int n=s.length();
    
    int k=0;
    loop(i,0,n) k+= s[i]=='1';

    if(k%2){
      cout<<-1<<endl;
      return;
    }
    else if(k==0) {
        cout<<0<<endl;
    }
    else if(k>=4){
        cout<<k/2<<endl;
        return;
    }

    vi v; 

    loop(i,0,n){
        if(s[i]=='1') v.pb(i+1);
    }

    if(v[1]-v[0] >1){
        cout<<1<<endl;
    }
    else{
      if(n==3) {
        cout<<-1<<endl;
      }
      else if(s=="0110"){
        cout<<3<<endl;
      }
      else cout<<2<<endl;
    }
    
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}