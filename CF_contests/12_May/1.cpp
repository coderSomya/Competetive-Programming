#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,k; cin>>n>>k;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
     
     int pref[n];
    pref[0]=v[0];
     for(int i=1; i<n; i++){
        pref[i]=pref[i-1]+v[i];
     }
    //  for(int i=n-1; i>=0;i--){
    //     suff[i]=suff[i+1]+v[i];
    //  }

    //  int ans=pref[2*k-1];

    //  int i=2*k-3;
    //  int j=n-1;
    //  for(int l=0; l<k-1; l++){
    //     ans=min(ans, suff[j-l]+pref[i-2*l]);
    //  }

    // cout<<pref[n-1]-ans<<endl;
  int sum=0;
    for(int i=0; i<n; i++) sum+=v[i];

//     int left=0;
//     int right=n-1;
//    int temp=0;
    

    int ans=-1;
    int i=0;
    int x=k;
    while(1+x--){
        // cout<<pref[n-1-(k-i/2)]<<endl;
        if(i==0){
            ans=max(ans, pref[n-1-k]);
        }

        else{
ans=max(ans, pref[n-1-(k-i/2)]-pref[i-1]);
        }
        
        i+=2;
    }

    cout<<ans<<endl;
}

int32_t main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}