/*
problem link ->
https://codeforces.com/problemset/problem/1814/C
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n,s1,s2;
    cin>>n>>s1>>s2;

    vector<int>v1,v2;

    vector<pair<int,int>> v;
    for(int i=0;i<n; i++){
     int r; cin>>r;
     v.push_back({r,i+1});
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int a=s1 ;int b=s2;

    for(int i=0; i<n; i++){
        if(a<b){
            v1.push_back(v[i].second);
            a+=s1;
        }
        else{
            v2.push_back(v[i].second);
            b+=s2;
        }
    }

    cout<<v1.size();
    for(int i=0; i<v1.size(); i++) cout<<" "<<v1[i];
    cout<<endl;
    cout<<v2.size();
    for(int i=0; i<v2.size(); i++) cout<<" "<<v2[i];
    cout<<endl;



}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}

