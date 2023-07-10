#include <bits/stdc++.h>
using namespace std;

#define int long long

#define debug(...) cout<<'[ '<<#__VA_ARGS__ <<':'<<(__VA_ARGS__)<<' ]'<<endl;

void solve(){
    int n,k; cin>>n>>k;

    int b=n%3;
    int m=n-b;

    int x=0; int alpha=0;
while(m){
while(m%3==0){
        m/=3;
        x++;
    }

    alpha+=m%3;
    m-= m%3;
}
    



    int mini=alpha+b;

//    cout<<alpha<<" "<<b<<endl;

    if(k<mini){

        cout<<"No"<<endl;
      return;
    }

     int dev=k-mini;
     if(dev%2){
        // cout<<"dev"<<dev<<endl;
        cout<<"No"<<endl;
        return;
     } 

     cout<<"Yes"<<endl;



}

int32_t main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}