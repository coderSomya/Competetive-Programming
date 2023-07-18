/*
https://www.desiqna.in/15111/intuit-oa-sde1-2023-may
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

int nc2(int n){
    return n*(n-1)/2;
}
 
 
void solve(){

    int n; cin>>n;
    int k; cin>>k;

    vector<int> v(n);
    umpii mp;
    for(int i=0; i<n; i++) {
        cin>>v[i];
        mp[v[i]]++;
    }
    int ans=0;

    if(k==0){
        for(auto x: mp){
            ans+=nc2(x.second);
        }

        cout<<ans<<endl;
        return;
    }

    // cout<<"here"<<endl;
    for(auto x: mp){
        // cout<<x.first<<" "<<endl;
        if(mp.find(x.first+k)!=mp.end()){
            ans+= mp[x.first]*mp[x.first+k];
        }
    }

    

    cout<<ans<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}