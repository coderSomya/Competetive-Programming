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

    int arr[n];
    loop(i,0,n) cin>>arr[i];

    int pref[n];
    pref[0]=arr[0];
    loop(i,1,n) pref[i]=pref[i-1]+arr[i];


    while(m--){

        int k,y,x;
        cin>>k>>y>>x;

        int ans=x;
        vector<int> v;
        for(int i=k-1; i<n ;i++){
            v.push_back(pref[i]-(i-k>=0 ? pref[i-k]:0));
        }

        for(int bit=30;bit>=0; bit--){

          if((x&(1<<bit))==0){
            vi h;
               for(auto x: v){
                if((x&(1<<bit))!=0){
                    h.push_back(x);
                }
               }
               if(h.size()>=y){
                v=h; ans+=(1<<bit);
               }
          }
        }

        cout<<ans<<endl;
    }
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}