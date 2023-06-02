/*
problem link->
https://codeforces.com/problemset/problem/1608/C
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    int a[n], b[n];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    
    vector<pair<pair<int,int>, int>> v;
    for(int i=0; i<n; i++) v.push_back({{a[i], b[i]},i});
    sort(v.begin(), v.end());
    vector<bool> ans(n);
    ans[v[n-1].second]=true;
    int pref[n];
    pref[0]=v[0].first.second;

    for(int i=1; i<n; i++) pref[i]=max(pref[i-1], v[i].first.second);
    int mini=v[n-1].first.second;

    for(int i=n-2; i>=0; i--){
        if(pref[i]>mini){
            ans[v[i].second]=true;
            mini=min(mini, v[i].first.second);
        }
        else ans[v[i].second]=false;
    }

    for(int i=0; i<n; i++){
        cout<<ans[i];
    }

    cout<<endl;

}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}