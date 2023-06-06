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


int nc2(int x)
{
    return x*(x-1)/2;
}
 
 
void solve(){
    take_n
    string s;
    int pref[n]={0};
    cin>>s;
    for(int i=0; i<n; i++){
        int x=s[i]-'0';
        if(i==0) pref[0]=x;
        else pref[i]=pref[i-1]+x;
    }
//loop(i,0,n) cout<<pref[i]<<endl;
  unordered_map<int, int> mp;
   loop(i,0,n){
      mp[pref[i]-(i+1)]++;
   }
  mp[0]++;
   int ans=0;
   for(auto x: mp){
    ans+=nc2(x.second);
   }

   cout<<ans<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}