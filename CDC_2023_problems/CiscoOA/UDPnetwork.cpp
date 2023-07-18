/*
https://www.desiqna.in/14058/cisco-ideathon-oa-july-2023-sde-1
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
    vector<pair<int,int>> v(n);
    for(int i=0;i<n; i++) {
        int a, b; cin>>a>>b;
        v[i]={a,b};
    }

    int rate; cin>>rate;

    int maxi; cin>>maxi;
    sort(v.begin(), v.end());
    
    int curr=0;
    int ans=0;

    for(int i=0; i<n; i++)
    {
        curr+= v[0].second;
        if(curr>rate){
            ans+=curr-maxi;
            curr=maxi;
        }
        if(i==n-1) break;
        int free= v[i+1].first-v[i].first-1;

        int deliv=rate*free;
        curr=max(curr-deliv,(int) 0);
    }
    
    cout<<ans<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}