#include <bits/stdc++.h>
  using namespace std;
  
  const int mod= 1e9+7;
  
  void solve(){
    int n; cin>>n;
    long long arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    
    
    vector<long long> v(60, 0);
    
    for(int i=0; i<n; i++){
      for(int j=0; j<60; j++){
        if(1ll*(arr[i]&(1ll<<j)) ==0) v[j]++;
      }
    }
    // for(auto x: v) cout<<x<<endl;
    long long ans=0;
    for(long long bit=0; bit<60; bit++){
      long long temp = (1ll*(v[bit]*(n-v[bit]))%mod);
      // cout<<temp<<endl;
      temp= (temp*((1ll<<bit)%mod))%mod;
      // cout<<temp<<endl;
      ans=(ans+temp)%mod;
      // cout<<ans<<endl;
    }
    
    cout<<ans<<endl;
  }

  int main() {

  solve();
  
  return 0;
  }