/*
problem link->
https://codeforces.com/problemset/problem/1798/C
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    int a[n];
    int b[n];
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i];
    }

    unordered_set<int> curr;
    int ans=1;
    for(int i=1;i*i<=a[0]; i++){
        if(a[0]%i==0) {
            curr.insert(b[0]*i);
            curr.insert(b[0]*a[0]/i);
        }
    }

    for(int i=1; i<n; i++){
        unordered_set<int>s;
        unordered_set<int> common;
        for(int j=1;j*j<=a[i]; j++){
            if(a[i]%j==0){
                s.insert(b[i]*j);
                s.insert(b[i]*a[i]/j);
                if(curr.find(b[i]*j)!=curr.end()) common.insert(b[i]*j);
                if(curr.find(b[i]*a[i]/j)!=curr.end()) common.insert(b[i]*a[i]/j);
            }
        }
        if(common.size()!=0) curr=common;
        else{
         ans++;
         curr=s;
        }
    }
    
   
    cout<<ans<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}