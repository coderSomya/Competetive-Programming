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
    int n,m; cin>>n>>m;

    vi ans(n,0);

    deque<int> dq;
    vi v;
    loop(i,1,n+1) {
         dq.pb(i);
    }
    umpii mp;
    loop(i,0,m){
        int x; cin>>x; v.pb(x);
    }
    
    for(int i=0; i<m; i++){
        int y= v[i];
        mp[y]++;

        if(mp[y]>1){
            dq.push_front(y);
            continue;
        }
        else{
            dq.push_front(y);
            while(mp.find(dq.back())!=mp.end() && mp[dq.back()]>1){
                mp[dq.back()]--;
                dq.pop_back();
            }

            int r=dq.back();
            if(mp.find(r)!=mp.end()){
                //n+1 wla hai
                mp[r]--;
                dq.pop_back();
            }
            else{
               int d= dq.back();
               ans[d-1]=i+1;
               dq.pop_back();
            }
         
        }
    }

    loop(i,0,n){
        if(ans[i]==0) ans[i]=-1;
    }

    loop(i,0,n){
        cout<<ans[i]<<" ";
    }

    cout<<endl;

    
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}