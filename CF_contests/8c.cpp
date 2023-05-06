#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m; cin>>n>>m;

    if(m==1 || n==1){
        cout<<"yes"<<endl;return;
    }

    else if(n%2==0){
        cout<<"NO"<<endl;
        return;
    }

    else{
        if(m>=n){
            cout<<"NO"<<endl;
            return;
        }
      else{
        //check if n has a factor >1 and less than m
       for(int i=2; i<=m; i++){
        if(n%i==0){
            cout<<"NO"<<endl; return;
        }
       }
       cout<<"YES"<<endl;
       return;
      }
    }
}

int main(){

    int t; cin>>t;
    while(t--) solve();

    return 0;
}
