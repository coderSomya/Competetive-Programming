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

// umpii mp;

    multiset<int>st;
int find(vector<int> &arr, int sum){

    int ans=0;
    int n= arr.size();
    
  for(int i=0; i<n; i++){
    if(st.count(arr[i])!=0){
        st.erase(st.find(arr[i]));
         if(st.count(sum-arr[i])!=0){
            ans++;
            st.erase(st.find(sum-arr[i]));
         }
         else st.insert(arr[i]);
    }
  }

  st.clear();

  for(int i=0; i<n; i++){
 st.insert(arr[i]);
  }

    return ans;
}
 
void solve(){
    int n; cin>>n;

    vector<int> arr(n);
    st.clear();

    for(int i=0; i<n; i++)
    {
       cin>>arr[i];
       st.insert(arr[i]);
    }

    int ans=1;
    for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
        int r= find(arr, arr[i]+arr[j]);
        ans = max(ans, find( arr, arr[i]+arr[j]));
      }
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}