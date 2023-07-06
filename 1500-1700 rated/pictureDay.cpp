#include <bits/stdc++.h>
using namespace std;

// #define debug(...) cout<<'[ '<<#__VA_ARGS__ ':'<<(__VA_ARGS__)<<' ]'<<endl;
#define debug(...) cout<<"[ "<<#__VA_ARGS__ ":"<<(__VA_ARGS__)<<" ]"<<endl;

void solve(){
  int n; cin>>n;
  vector<pair<int,int>> v;
  for(int i=0; i<n/2; i++){
    int x,y; cin>>x>>y;
    v.push_back({min(x,y), max(x,y)});
  }

  sort(v.begin(), v.end());

  vector<pair<int,int>> a,b;
  a.push_back(v[0]);

  for(int i=1; i<n/2; i++){
    if(v[i].first>=a.back().second){
        a.push_back(v[i]);
    }
    else{
        b.push_back(v[i]);
    }
  }

  int m=(int)b.size();
  debug(m);

  for(int i=1; i<m; i++){
    if(b[i].first>=b[i-1].second) continue;

    else{
        cout<<"-1"<<endl;
        return;
    }
  }
//   cout<<"hello"<<endl;
  reverse(b.begin(), b.end());
  for(auto x: a) cout<<x.first<<" "<<x.second<<" ";
  for(auto x: b) cout<<x.second<<" "<<x.first<<" ";
  cout<<endl;
}

int main(){
    // int t; cin>>t;
    // while(t--)
     solve();

    return 0;
}