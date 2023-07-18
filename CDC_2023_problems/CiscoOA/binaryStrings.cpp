/*
https://www.desiqna.in/13127/cisco-sde1-coding-questions-and-solutions-india-april-2023
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
string s; cin>>s;

vector<pair<int,int>> v;
v.push_back({s[0]-'0', 1});
for(int i=1; i<n; i++){
  if(s[i]==s[i-1]) v.back().second++;
  else v.push_back({s[i]-'0', 1});
}

int ans=0;
n= v.size();
for(int i=1; i<n; i++){
  ans+= min(v[i].second, v[i-1].second);
}

cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}