/*
problem link->
https://codeforces.com/problemset/problem/1658/C
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    int c[n];
    int start=-1;
    for(int i=0; i<n; i++) {
        cin>>c[i];
        if(c[i]==1) start=i;
    }

    if(start==-1){
        cout<<"NO"<<endl;
        return ;
    }

    int p[n];
    for(int i=0; i<n; i++){
        p[i]=c[(i+start)%n];
    }

    for(int i=1; i<n; i++){
        if(p[i]==1 || p[i]-p[i-1]>1){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}
