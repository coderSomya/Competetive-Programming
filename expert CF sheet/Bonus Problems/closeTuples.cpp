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

int bs(const vector<int> &v, int target){
    //return index of element just smaller than or equal to target

    int l=0; int h=v.size()-1;
    int ans =0;
    while(l<=h){
        int mid=(l+h)/2;

        if(v[mid]<=target){
            ans=mid;
            l=mid+1;
        }
        else h=mid-1;
    }

    return ans;
}

int calc(int start, int end, int atleast){
    int got= end-start+1;

    return max(got-atleast+1,(int)0);
}
 
 
void solve(){
    int n,m,k; cin>>n>>m>>k;

    vi v(n);
    loop(i,0,n) cin>>v[i];
    sort(v.begin(), v.end());

    int ans=0; 
    loop(i,0,n){
        int curr=v[i];
        int need=curr+k;
        //not more than that
        int idx=bs(v,need);
        ans+= calc(i,idx,m);
        ans%=mod;
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}