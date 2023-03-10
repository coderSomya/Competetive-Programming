/*
problem link ->
https://codeforces.com/problemset/problem/1801/B
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

    vector<pair<int,int>>v;
    loop(i,0,n) {
        int x,y; cin>>x>>y;
        v.pb({x,y});
    }
    int suff[n]; suff[n-1]=v[n-1].second;
    for(int i=n-2;i>=0; i--) suff[i]=max(suff[i+1], v[i].second);
    set<int> st;
    st.insert(-inf);
    sort(v.begin(), v.end());
   int ans=2*inf;
    loop(i,0,n){
        
        //let a[i] be the max of from a
        //suff[i+1] will be one candidate
        //upperbound(a[i]) will be another candidate
        auto x= lower_bound(st.begin(), st.end(), v[i].first);
        x--;
  
        int temp;

        if(i==0){
          
            temp= abs(suff[i+1]-v[i].first);
        }
        else if(i==n-1){
            
           temp=inf;
           loop(j,0,n-1) temp=min(temp, abs(v[j].second-v[n-1].first));

        }
        else{
            //general case
            if(suff[i+1]>=v[i].first){
               temp=suff[i+1]-v[i].first;
            }
            else{
             temp= min(v[i].first-suff[i+1], v[i].first-*x);
            }
        }
      
        st.insert(v[i].second);
ans= min(ans, temp);

    }
   
    cout<<ans<<endl;
    

    

}

int32_t main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}