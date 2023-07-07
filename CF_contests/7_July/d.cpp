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
    int n,d,h;
    cin>>n>>d>>h;

    double ans=0.0;

    vi y(n);
    loop(i,0,n) cin>>y[i];
  double sz=d*h/2.00000000;
    sort(y.begin(), y.end());
      ans+= sz;
    for(int i=1; i<n; i++){
        ans+=sz;
        if(y[i-1]+h>y[i]){
            ans-=((y[i-1]+h-y[i])*(y[i-1]+h-y[i])*sz)/(h*h);
        }
    }

    cout<<setprecision(15);
    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}