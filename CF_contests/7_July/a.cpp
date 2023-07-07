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
    int a[n]; int b[n];
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i];
    }


    vi pos(n);
    int ans=inf;

    for(int i=1; i<=200; i++){
        bool flag=false;
        int ct=0;
        for(int j=0; j<n; j++){
            if(a[j]<=i && a[j]+b[j]>=i){
                continue;
            }
            else if(a[j]>=i && a[j]-b[j]>=i){
                 ct++;
            }
            else{
                flag=true;
                break;
            }
        }


        if(flag) continue;
        else ans=min(ans, ct);
    }

    cout<<ans<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}