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
    vector<int> arr;
    loop(i,0,n){
        int x; cin>>x;
        arr.pb(x);
    }
    
    vector<int> v;
    vector<int> sorted(arr);
    sort(sorted.begin(), sorted.end());
    vi pref(n);
    set<int>st;
    pref[0]=sorted[0];
    for(int i=1; i<n;i++){
      pref[i]=pref[i-1]+sorted[i];
    }
   
   int last=-1;
    for(int i=0; i<n-1; i++){
      if(pref[i]<sorted[i+1]) last=i;
    }
    
    for(int i=last+1; i<n; i++){
        st.insert(sorted[i]);
    }
    
    for(int i=0; i<n; i++){
        if(st.find(arr[i])!=st.end()){
            v.pb(i+1);
        }
    }

 
    cout<<v.size()<<endl;
    for(auto x: v) cout<<x<<" ";
    cout<<endl;




}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}