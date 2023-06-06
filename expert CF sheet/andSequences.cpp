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

int nc2(int x){
    return (x*(x-1)/2)%mod;
}

int fact[200005];
 
 
void solve(){
    take_n
    take_arr
    int prefand[n]; prefand[0]=arr[0];
    int suffand[n]; suffand[n-1]=arr[n-1];
    
    int ct=0;
    loop(i,1,n){
        prefand[i]=prefand[i-1]&arr[i];
        suffand[n-1-i]=suffand[n-i]&arr[i];
    }
    loop(i,0,n){
        if(i==0){
        ct+=(suffand[i+1]==arr[i]);
        }
        else if(i==n-1){
        ct+=(prefand[i-1]==arr[i]);
        }
        else ct+= ((prefand[i-1]&suffand[i+1])== arr[i]);
    }


    int ans=(ct*(ct-1))%mod;
    ans = (ans*fact[n-2]) % mod;
   cout<<ans<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
fact[0]=1;
loop(i,1,200005) fact[i]=(fact[i-1]*i)%mod;
while(t--) solve();
return 0;
}