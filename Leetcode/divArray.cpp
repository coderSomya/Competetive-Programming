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


vector<int> divisibilityArray(string word, int m) {
       int n= word.size();
      int dp[n];
      //dp[i]= number from 1...i-1 mod m
      vi ans(n);
      dp[0]= (word[0]-'0')%m;
      ans[0]= dp[0]==0;
      for(int i=1; i<n; i++){
         dp[i]=(((dp[i-1]%m) * (10 %m)%m)+ (word[i]-'0')%m)%m;
         ans[i]= dp[i]==0;
      }
     return ans;
}
 
void solve(){
    string word; cin>>word; int m; cin>>m;
    vi v = divisibilityArray(word, m);
    int n=word.size();
    loop(i,0,n) cout<<v[i]<<" ";
    cout<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}