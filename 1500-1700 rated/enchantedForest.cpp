/*
problem link ->
https://codeforces.com/problemset/problem/1687/A
*/

#include <bits/stdc++.h>
using namespace std;

const int inf=1e9;

#define int long long

void solve(){
    int n,k; cin>>n>>k;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int pref[n]; pref[0]=arr[0];
    for(int i=1; i<n; i++) pref[i]=pref[i-1]+arr[i];

    int ans=-inf;

    //ans = max over all l= max sum of l + l*k -l*(l+1)/2

    int l=min(n,k);
    for(int i=0; i<n; i++){
        if(i+l-1>=n) break;
        int temp=pref[i+l-1]-(i>0? pref[i-1]: 0);
        ans=max(ans, temp);
    }

    ans+= l*k -l*(l+1)/2;
    cout<<ans<<endl;


}

int32_t main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}