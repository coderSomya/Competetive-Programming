/*
problem link ->
https://codeforces.com/problemset/problem/1614/C
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod=1e9+7;
const int N=2*1e5;

int fact[N+1];
int invfact[N+1];

int ncn(int x){
    return ((fact[x]*invfact[x/2])%mod*invfact[x/2])%mod;
}

int binexpo(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;

    int res=binexpo(a,b/2);
    res= (res*res)%mod;
    if(b%2) res=(res*a)%mod;
    return res;
}

int calc(int x){

    if(x%2) return binexpo(2,x-1);

    else return (binexpo(2,x)-2+ncn(x))/2;
}

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> v(n+1,vector<int>(31,0));

  
    
    for(int p=0; p<m; p++){
      int l,r,x; cin>>l>>r>>x;
      for(int i=0; i<=30; i++){
        if(!(x&(1<<i))) {
            v[l][i]+=1;
            if(r+1<=n) v[r+1][i]-=1;
        }
      }
    }
  

    int freq[31]={0};

    for(int i=0; i<31; i++){
       for(int j=1;j<=n; j++){
        v[j][i]=v[j-1][i]+v[j][i];
       }
    }

    for(int i=0; i<=30; i++){
        for(int j=1; j<=n; j++) if(v[j][i]<=0) v[j][i]=1;
        else v[j][i]=0;
    }


    for(int i=0;i<=30; i++){
        for(int j=1; j<=n; j++){
            freq[i]+=v[j][i];
        }
    }

    int ans=0;

 

    for(int i=0; i<31; i++) ans= (ans+((binexpo(2,i)*calc(freq[i]))%mod)*binexpo(2,n-freq[i])%mod)%mod;

    cout<<ans<<endl;


}

int32_t main(){
    int t; cin>>t;

    fact[0]=1;
    for(int i=1; i<=N; i++) fact[i]=(fact[i-1]*i)%mod;

    invfact[N]=binexpo(fact[N], mod-2);

    for(int i=N-1;i>=0; i--) invfact[i]=(invfact[i+1]*(i+1))%mod;

    while(t--) solve();

    return 0;
}