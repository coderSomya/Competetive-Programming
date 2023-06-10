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
    take_n
    take_arr
    set<int> st;
    loop(i,1,n-1){
        if((arr[i]-arr[i-1])*(arr[i]-arr[i+1])>0) st.insert(i);
    }

    int ans=st.size();
    int two=0;
    int three=0;

    for(auto x: st){
        if(st.find(x+1)!=st.end() && st.find(x-1)!=st.end()){
             three++;
        }
        else if(st.find(x+1)!=st.end() || st.find(x-1)!=st.end()){
            two++;
        }
    }

    if(three>0) ans-=3;
    else if(two>0) ans-=2;
    else {
        ans-=1;
    }
    
    if(ans<0) ans=0;
    cout<<ans<<endl;

    
}

  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}