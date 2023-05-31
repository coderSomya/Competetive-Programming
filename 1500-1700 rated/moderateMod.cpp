/*
problem link->
https://codeforces.com/problemset/problem/1603/B
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x,y;
    cin>>x>>y;

    int n;
    if(y<x) n=x+y;

    else if(y==x) n=x;
    
    else{
        int m=y%x;
        int p=m/2;
        int k=y/x;
        n=k*x+p;
    }
    
    cout<<n<<endl;

}


int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}