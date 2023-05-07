/*
problem link->
https://codeforces.com/problemset/problem/1774/D
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
  
  int n,m; cin>>n>>m;

vector<vector<int>> v(n);
vector<pair<int,int>> ones;
int total=0;
  for(int i=0; i<n; i++){
    int ct=0;
    for(int j=0; j<m; j++){
        int x; cin>>x;
        if(x==1) ct++;
        v[i].push_back(x);
    }
    ones.push_back({ct,i});
    total+=ct;
  }


if(total%n!=0){
    cout<<-1<<endl;
    return;
}

int r=total/n;

sort(ones.begin(), ones.end());
vector<pair<int, vector<int>>> requirement;
vector<vector<int>> supply(m);
for(int i=0; i<n; i++){

    if(ones[i].first<r){
        vector<int> req;
       for(int j=0; j<m; j++){
        if(v[ones[i].second][j]==0) req.push_back(j);
       }
       requirement.push_back({ones[i].second, req});
    }
    else if(ones[i].first>r){
        supply[ones[i].first].push_back(ones[i].second);
    }
}

for(int i=0; i<n; i++){
    for(auto x: supply[i])cout<<x<<" ";
    cout<<endl;
}


}
int main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}