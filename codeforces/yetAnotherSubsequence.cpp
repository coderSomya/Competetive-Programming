#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int mod= 998244353;
const int N = 1e3+4;


int fact[N+1];
int invfact[N+1];


int binexpo(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;

    int res=binexpo(a, b/2);
    res*=res;
    res%=mod;
    if(b%2) res*=a;
    res%=mod;

    return res;
}

void init(){

    fact[0]=1;
    for(int i=1; i<=N; i++){
        fact[i]=(fact[i-1]*i)%mod;
    }

    invfact[N]=binexpo(fact[N], mod-2);

    for(int i=N-1; i>=0; i--){
        invfact[i]=((i+1)*invfact[i+1])%mod;
    }


}

int ncr(int n, int r){

  if(r>n) return 0;

  int res= ((fact[n]*invfact[r]%mod)* invfact[n-r])%mod;
  return res%mod;
}

void solve(){
    int n; cin>>n;
    int arr[n+1];
    for(int i=1; i<=n; i++) cin>>arr[i];

    int dp[n+2]={0};
    dp[n+1]=1;

    for(int i=n; i>0; i--){
if(arr[i]<=0) continue;
        for(int j=i+1; j<=n+1; j++){
            int req=arr[i];
            int temp=0;
            temp+=ncr(j-i-1, req);
            temp*=dp[j];
            temp%=mod;
            dp[i]+=temp;
            dp[i]%=mod;
        }
    }


    int ans=0;
    for(int i=0; i<n; i++) {
        ans+= dp[i]; ans%=mod;
    }

    cout<<ans<<endl;
}

int32_t main(){

    init();

    solve();

    return 0;
}