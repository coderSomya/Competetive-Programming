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

int n,m; 
string s,t;
 
 
void solve(){

    cin>>n>>m;
    cin>>s>>t;

    int ans=-1;

    int left[m];
    int j=0;
    for(int i=0; i<n && j<m; i++){
        if(s[i]==t[j]){
            left[j]=i;
            j++;
        }
    }

    int right[m];
    j=m-1;
    for(int i=n-1; i>=0 && j>=0;i--){
        if(s[i]==t[j]){
            right[j]=i;
            j--;
        }
    }

    for(int i=0; i<m-1; i++){
      ans=max(ans, right[i+1] - left[i]);
    }


    cout<<ans<<endl;


}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}