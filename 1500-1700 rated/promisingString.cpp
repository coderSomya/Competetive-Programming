/*
problem link->https://codeforces.com/problemset/problem/1660/F1
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int arr[30002];
int extra;



void solve(){
    cin>>n;
     memset(arr,0, sizeof(arr));
     string s; cin>>s;
     arr[0]=n;
    for(int i=1; i<=n; i++){
      arr[i]=(s[i-1]=='-'?1:-1)+arr[i-1];
    }

    int ans=0;

    for(int i=1; i<=n; i++){
  for(int j=0; j<i; j++) {
    if(arr[j]-arr[i]>=0 && (arr[j]-arr[i])%3==0) ans++;
  }
    }
    
    
    cout<<ans<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();


    return 0;
}