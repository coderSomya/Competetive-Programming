/*
problem link->
https://codeforces.com/problemset/problem/1615/C
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    string a,b; cin>>a>>b;
    int c1,c0,w1,w0;
    c1=c0=w0=w1=0;
    for(int i=0; i<n; i++){
        if(a[i]==b[i]){
            if(a[i]=='1') c1++;
            else c0++;
        }
        else{
            if(a[i]=='1') w1++;
            else w0++;
        }
    }
    
    int ans=1e9;
    if(w0==w1) ans=2*w0;

    //change the setup, if there is atleast one c1
    if(c1>0){
        /*
        correct ones=1+w0;
        correct zeroes=w1;
        wrong zeroes=c1-1;
        wrong ones=c0
        */
       if(c1-1==c0) ans=min(ans, 1+2*c0);
    }

    //or
    if(w1>0){
        /*
        correct ones=w0;
        correct zeroes=w1-1;
        wrong zeroes=c1;
        wrong ones=1+c0;
        */

       if(1+c0==c1) ans=min(ans, 1+2*c1);
    }

    if(ans==1e9) cout<<-1<<endl;

    else cout<<ans<<endl;


}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}