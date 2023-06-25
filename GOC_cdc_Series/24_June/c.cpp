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
 
int bs(vector<pair<int,int>> &v, int x){

}
void solve(){
    int n,m; cin>>n>>m;
    int a[n], b[n];
    int c[m], d[m];
    loop(i,0,n) cin>>a[i]>>b[i];
    loop(i,0,m) cin>>c[i]>>d[i];

    vector<pair<int,int>> need;
    vector<pair<int,int>> have;
    loop(i,0,n) need.pb({a[i], b[i]}); 
    loop(i,0,m) have.pb({c[i], d[i]}); 

    sort(need.begin(), need.end());
    sort(have.begin(), have.end());

    multiset<int>st;
    int curr=n-1;
    int last=m-1;
    while(curr>=0){
        int idx= bs(have, need[curr].first);
        if(idx>=0){
            for(int i=idx; i<=last; i++){
                st.insert(have[i].second);
            }

            last=idx-1;
        }
      

        else{
            cout<<"NO"<<endl;
            return;
        }
    }

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}