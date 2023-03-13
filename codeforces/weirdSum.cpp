/*
problem link ->
https://codeforces.com/problemset/problem/1648/A
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
 
int res(vi &v){
    //returns required sum from a vector

    int ans=0;
    sort(v.begin(), v.end());
    int n=v.size();
    loop(i,0,n){
        ans+= v[i]*(i-(n-1-i));
    }

    return ans;
}
vector<vector<pair<int,int>>> total(100001);
void solve(){
   total.clear();
   int ans=0;
   int n,m; cin>>n>>m;
   loop(i,0,n){
    loop(j,0,m){
     int x; cin>>x;
     total[x].pb({i,j});
    }
   }
//    cout<<"here atleast"<<endl;

   for(int i=0 ; i<100001; i++){
    if(total[i].size()>1){
        vi a,b;
        for(auto y: total[i]){
          a.pb(y.first); b.pb(y.second);
        }

        // loop(i,0,a.size()) cout<<a[i]<<" ";
        // cout<<endl;

        ans+= res(a)+res(b);
    }
   }

   cout<<ans<<endl;
   
}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--)
 solve();
return 0;
}