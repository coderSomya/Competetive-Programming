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
 
const int N= 200000;
int n; int arr[101];
int32_t dp[101][2*N+1];
 
int mini(int i, int sum){
 
    if(i==n){
        if(sum==N) {
            return 0;
        }
        else return N+1;
    }
 
    if(dp[i][sum]!=-1) return dp[i][sum];
 
    int op1=mini(i+1,sum+arr[i]);
    int op2=mini(i+1,sum-arr[i]);
 
    return dp[i][sum]= min(1+mini(i+1,sum),min(op1, op2));
}
 
 
void solve(){
    cin>>n;
    loop(i,0,n) cin>>arr[i];
 
    memset(dp, -1, sizeof(dp));
 
    int ans=mini(0,N);
    if(ans!=0){
        cout<<0<<endl;
        return;
    }
 
    //maybe removing smallest element would work?
    //NO, it doesnt :)
    int res=20; int idx=-1;
    for(int i=0; i<n; i++){
        int temp;
        for(int bit=0;bit<12;bit++){
            if(arr[i]&(1<<bit)){
              temp=bit;
              break;
            }
        }
        if(temp<res){
            idx=i;
        }
        res=min(res, temp);
    }

    
   cout<<1<<endl;
   cout<<idx+1<<endl;
    
}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}