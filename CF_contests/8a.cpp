/*
problem link ->
https://codeforces.com/contest/1826/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    //O(n^2)

    for(int i=0; i<=n; i++){
        int y=0;
        for(int j=0; j<n; j++){
            y+=(arr[j]<=i);
        }
        if(n-y==i){
            cout<<i<<endl;
            return;
        }
    }

    cout<<-1<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}