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

int check(vector<int> &arr, int m , int k){

    int n=arr.size();
    int ct=0;
    for(int i=1; i<n; i++){
        if(arr[i]*arr[i-1]<=k){
            arr[i]*=arr[i-1];
        }
        else ct++;
    }

    return ct<=m;
}

 
 
void solve(){
    int n=6;
    vector<int> arr = {2,3,3,7,3,5};
 

    int k=20;
    int ct=0;

   int l=1; int h=n;
   int ans=n;
   while(l<=h){
    int mid=(l+h)/2;

    if(check(arr, mid, k)){
        h=mid-1;
        ans=mid;
    }
    else l=mid+1;
   }

    cout<<ans<<endl;

    

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}