/*
problem link->
https://codeforces.com/problemset/problem/1672/D
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    int a[n+1],b[n+1];
    for(int i=0;i<n; i++) cin>>a[i];
    for(int i=0;i<n; i++) cin>>b[i];
    a[n]=b[n]-1;
   int la=n-1;
   int lb=n-1;
   int freq[n+1]={0};
   while(la>=0 && lb>=0){
    if(a[la]==b[lb]){
        la--; lb--;
    }
    else{
        if(b[lb+1]==b[lb]){
            freq[b[lb]]++;
            lb--;
        }
        else{
            if(freq[a[la]]>0) {
                freq[a[la]]--;
                la--;
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
    }
   }

   cout<<"YES"<<endl;
}


int main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}