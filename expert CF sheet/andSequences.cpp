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

bool isSuper(int a,int b){
    for(int i=0; i<30; i++){
        if(b&(1<<i)){
            //ith bit is set in b then it has to be set in a
            if(!(a&(1<<i))) return false;
        }
    }

    return true;
}
 
 
void solve(){
    take_n
    take_arr
  
    int ct=0;
    int x=arr[0];
    loop(i,1,n){
       x=x&arr[i];
    }
    loop(i,0,n){
        ct+=isSuper(x,arr[i]);
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