#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n; cin>>n;
    if(n==2){
        cout<<-1<<endl;
        return;
    }
    if(n%2){
        cout<<2<<endl;
        return;
    }

    if(n==6){
        cout<<3<<endl;
        return;
    }

    if(n%4==2){
        cout<<4<<endl;
        return;
    }

    for(int i=3; (i*(i-1))/2<=n; i++){
       if(2*n%i!=0) continue;       
        int x= 2*n/i - (i-1);
       if(x> 0 && x%2==0){
        cout<<i<<endl;
        return;
       }
    }

    cout<<-1<<endl;
}

int32_t main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}