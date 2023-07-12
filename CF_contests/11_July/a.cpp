#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b; cin>>a>>b;

    if(a>1){
        cout<<1<<endl;
        return;
    }

   cout<<b+1<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}