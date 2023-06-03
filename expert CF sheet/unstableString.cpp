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
    string s; cin>>s;

    int n=s.length();

    vector<vector<int>> lstp(2,vector<int>(2,-1));
   int ans=0;
    for(int i=0; i<n; i++)
    {
        int j=i-1;
        int p=i%2;

        if(s[i]!='1') j=min(j,max(lstp[0][1-p], lstp[1][p]));

        if(s[i]!='0') j=min(j,max(lstp[0][p], lstp[1][1-p]));

        ans+=i-j;

        if(s[i]!='?') lstp[s[i]-'0'][p]=i;
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}