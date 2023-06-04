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
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    vector<string> v;
    string s="";
    for(int i=0; i<n; i++){
      if(s.empty()){
        s.push_back(arr[i]+'0');
        v.pb(s);
      }

      else{
       if(arr[i]==1){
       s.pb('.'); s.pb('1');
       v.pb(s);
       }
       else{
        while(!s.empty() && (s.back()=='.' || (arr[i]- (s.back()-'0'))!=1)){
            s.pop_back();
        }
        if(!s.empty()) s.pop_back();
        s.push_back(arr[i]+'0');
        v.pb(s);
       }
      }
    }


    for(auto x: v) cout<<x<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}