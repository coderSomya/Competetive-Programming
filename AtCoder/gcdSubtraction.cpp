#include <bits/stdc++.h>
using namespace std; 



void solve(){
    long long a,b; cin>>a>>b;



    int ct=0;

    while(a && b){
      long long gc= __gcd(a,b);
      a/=gc; b/=gc;
      a--; b--;
      ct++;
          
    }
    

    cout<<ct<<endl;


}

int main(){
    // int t;cin>>t;
    // while(t--) 
    solve();

    return 0;
}