/*
problem link ->
https://codeforces.com/problemset/problem/1833/F
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod= 1e9+7;
const int N=2*1e5;
int fact[N+1];
int invfact[N+1];

int ncr(int n, int r){

    if(r>n) return 0;

    return ((fact[n]*invfact[n-r])%mod*invfact[r])%mod;
}

int binexpo(int a, int b){
    if(b==0) return 1;

    int res=binexpo(a,b/2);
    if(b%2) return ((res*res)%mod*a)%mod;
    else return (res*res)%mod;
}


int inv(int n){
   return binexpo(n,mod-2);
}

void solve(){
    int n,m; cin>>n>>m;

    int arr[n]; 
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);

    vector<pair<int,int>> v;
    v.push_back({arr[0], 1});

    for(int i=1; i<n; i++){
     if(arr[i]==v.back().first) v.back().second++;
     else v.push_back({arr[i],1});
    }


    int temp=1;
    int ans=0;
    
    int l=0;
     bool flag=false;
    n=(int)v.size();
    temp*=v[0].second;
    for(int i=1; i<n; i++){
       if(v[i].first-v[l].first<m){
          if(i==n-1) flag=true;
          temp=temp*v[i].second%mod;
       }
       else{
       
        i--;
        ans=(ans+(temp*ncr(i-l+1,m))%mod)%mod;
        temp=temp/v[l].second;
        l++;
       }
    }
    
    if(flag || n==1) ans= (ans+temp*ncr(n-l,m))%mod;

    cout<<ans<<endl;

    
}

int32_t main(){
    
    fact[0]=1;
    for(int i=1; i<=N; i++){
        fact[i]=(fact[i-1]*i)%mod;
    }

   invfact[N]=inv(fact[N]);
   for(int i=N-1;i>=0; i--){
    invfact[i]=((i+1)*invfact[i+1])%mod;
   }

    int t; cin>>t;
    while(t--) solve();


    return 0;
}