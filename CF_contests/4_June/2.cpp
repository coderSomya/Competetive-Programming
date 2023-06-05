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
vector<int>arr(n);
loop(i,0,n) cin>>arr[i];

    int i,j,k;
    
    for(int l=0; l<n; l++){
        if(arr[l]==1) i=l;
        if(arr[l]==2) j=l;
        if(arr[l]==n) k=l;    
    }

    if((i-k)*(j-k)<0){
        //swap any two
        cout<<1<<" "<<1<<endl;
    }
    else{
        
        if(max({i,j,k})==k){
        cout<<1+k<<" "<<1+(max(i,j))<<endl;
        }
        else{
       cout<<1+k<<" "<<1+min(i,j)<<endl;
        }
        
    }

    
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}