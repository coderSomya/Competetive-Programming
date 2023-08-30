#include <bits/stdc++.h>
using namespace std;


int bs(const vector<pair<int,int>> &v, int lo, int hi, int val){

    int l=lo; int r=hi;
    int ans=val;
    while(l<=r){
        int mid=(l+r)/2;
        if(v[mid].first<=val){
          ans=v[mid].second;
          l=mid+1;
        }
        else {
            r=mid-1;
        }
    }

    return ans;
}

void solve(){
    int n; cin>>n;
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        int l,r,a,b;
        cin>>l>>r>>a>>b;
        v.push_back({l,b});
    }

    sort(v.begin(), v.end());

    vector<pair<int,int>> req;
    req.push_back(v[0]);

    for(int i=1; i<n; i++){
        if(v[i].first<=req.back().second){
            req.back().second=max(v[i].second, req.back().second);
        }
        else req.push_back(v[i]);
    }
    

    int q; cin>>q;
  while(q--){
    int x; cin>>x;

    int res=bs(req, 0, req.size()-1, x);
    int ans=max(x, res);

    cout<<ans<<" ";

  }

  cout<<'\n';



}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}