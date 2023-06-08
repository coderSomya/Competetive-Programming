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
    int arr[n];
    loop(i,0,n) cin>>arr[i];

    int ans=-1;
    
    int l=1; int r=n;
    while(l<=r){
        int m=(l+r)/2;

        vector<int>b(n);
        for(int i=0; i<n; i++){
          if(arr[i]>=m) b[i]=1;
          else b[i]=-1;
        }

        for(int i=1; i<n; i++){
             b[i]+=b[i-1];
        }

        int mx=b[k-1];
        int mn=0;
        for(int i=k; i<n; i++){
            mn=min(mn, b[i-k]);
            mx=max(mx, b[i]-mn);
        }

        if(mx>0){
            ans=m;
            l=m+1;
        }
        else r=m-1;
    }

    cout<<ans<<endl;



   
}

  
  
int32_t main(){
solve();
return 0;
}