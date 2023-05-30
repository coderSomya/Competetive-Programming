/*
problem link->
https://codeforces.com/problemset/problem/1610/C
*/

#include <bits/stdc++.h>
using namespace std;

const int N=2e5;
int a[N+1],b[N+1];
int n; 


bool check(int k){

    int taken=0;
    //greedily pick elements
    for(int i=0; i<n; i++){
    if(k-(taken+1)<=a[i] && taken<=b[i]) taken++;
    }

    return taken>=k;
}


void solve(){
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i]>>b[i];

    int l=0; int h=n;

    //binary search on no. of people to take

    int ans=0;

    while(l<=h){
        int mid=(l+h)/2;

        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else h=mid-1;
    }     

    cout<<ans<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}
