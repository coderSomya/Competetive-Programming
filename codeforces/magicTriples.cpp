/*
problem link ->
https://codeforces.com/problemset/problem/1822/G1
*/

#include <bits/stdc++.h>
using namespace std;

int choose3(int a)
{
    return a*(a-1)*(a-2)/6;
}
vector<pair<int,int>> squares;
void solve(){

    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
   
   int ans=0;

    unordered_map<int,int> mp;
    for(int i=0; i<n;i++) mp[arr[i]]++;

   for(int i=0; i<n; i++){
    ans+=(mp[arr[i]]-1)*(mp[arr[i]]-2);
   }

    for(int i=0; i<n;i++){
        for(auto x: squares){
            if(mp.find(arr[i]*x.first)!=mp.end() && mp.find(arr[i]*x.second)!=mp.end()){
               ans+=mp[arr[i]*x.first]*mp[arr[i]*x.second];
            }
        }
    }

    cout<<ans<<endl;

}

int main(){
    for(int i=2; i*i<1000001; i++){
        squares.push_back({i*i,i});
    }
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}