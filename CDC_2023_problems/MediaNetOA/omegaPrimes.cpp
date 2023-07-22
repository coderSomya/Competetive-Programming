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
#define p_arr(A,n)      loop(i,0,n) cout<<A[i];
#define pln_arr(A,n)    loop(i,0,n) cout<<A[i]<<endl
#define take_n          int n; cin>>n;
#define take_arr        int arr[n]; loop(i,0,n) cin>>arr[i];
  
  
const int mod= 1e9+7;
const int inf= 1e15;

vector<int> v;
vector<vector<int>> di(31);

vi primes{2,3,5,7,11,13,17,19,23,29};

const int N= 2e4;
int n;
int dp[N][(1<<10)];

int rec(int i, int mask, vector<int>&arr){
    // cout<<mask<<endl;

    if(i==n) return (mask!=0);
   
   bool take=true;
  int temp_mask=mask;

  if(dp[i][mask]!=-1) return dp[i][mask];

   for(auto x: di[arr[i]]){
    if((mask&(1<<x))!=0) take=false;
    else temp_mask = temp_mask | (1<<x);
   }
   int temp=rec(i+1, mask,arr);
   if(take){
    temp+=rec(i+1, temp_mask, arr);
    temp%=mod;
   }

   return dp[i][mask]=temp%mod;
   
}
 
 
void solve(){

    vector<int> v{1,2,3,5,6,7,10,11,13,14,15,17,19,21,22,23,26,29,30};

    set<int> st;
    for(auto x: v)st.insert(x);

    v.clear();
    cin>>n;

    memset(dp,  -1, sizeof(dp));

    for(int i=2; i<=30; i++){
       for(int j=0; j<primes.size(); j++){
        if(i%primes[j]==0){
            di[i].pb(j);
        }
       }
    }


    
    vector<int> arr;

    
    loop(i,0,n){
        int x; cin>>x;
        if(st.count(x)!=0) arr.pb(x);
    }

    n=(int) arr.size();
  //2 30 15 22
  //2 15
  //22 15

    int ans= rec(0,0,arr);
    cout<<ans%mod<<endl;

    
    


}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--)
solve();
return 0;
}