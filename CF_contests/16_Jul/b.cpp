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
    int n,k; cin>>n>>k;

    vector<int> v(n);
    set<int> st;
    for(int i=0; i<n; i++) {
        cin>>v[i]; st.insert(v[i]);
    }

    umpii last;

    for(auto x: st){
        last[x]=-1;
    }

    umpii ans;
    umpii second;

     for(auto x: st){
        ans[x] = -1;
        second[x]=-1;
     }

    for(int i=0; i<n; i++){
     
       if(i-1-last[v[i]] >= ans[v[i]]){
        second[v[i]]=ans[v[i]];
        ans[v[i]]=i-1-last[v[i]];
       }
       else if(i-1-last[v[i]] >= second[v[i]]){
        second[v[i]]=i-1-last[v[i]];
       }

       last[v[i]]=i;
    }

    // int ans=0; 

    int res=inf;
//   for(auto x: st) cout<<ans[x]<<" ";
//     cout<<endl;
//       for(auto x: st) cout<<second[x]<<" ";
//     cout<<endl;
    
    for(auto x: st){
        // ans[x]=max(ans[x], n-1- last[x]);

         if(n-1-last[x] >= ans[x]){
        second[x]=ans[x];
        ans[x]=n-1-last[x];
       }
       else if(n-1-last[x] >= second[x]){
        second[x]=n-1-last[x];
       }

        res=min(res, max(ans[x]/2, second[x]));
    }
  


   cout<<res<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}