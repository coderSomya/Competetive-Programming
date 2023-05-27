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
   string s; cin>>s;
   int n=s.length();
   int pref[n][4];
   int suff[n][4];

   vi as;
   vi gs;

   for(int i=0 ; i<n; i++){
    if(s[i]=='A') as.pb(i);
    if(s[i]=='G') gs.pb(i);
   }
    unordered_map<char,int> mp;
    mp['A']=0;
    mp['C']=1;
    mp['T']=2;
    mp['G']=3;



    

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}