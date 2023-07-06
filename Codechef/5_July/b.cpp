#include <bits/stdc++.h>
using namespace std;


#define int long long



int nc2(int x){
    return x*(x-1)/2;
}

void solve2(){

     int n; int q;
    
      cin>>n>>q;

    vector<int> v(n,0);
    for(int i=0; i<n; i++) cin>>v[i];

    //precompute

    sort(v.begin(), v.end());
     
  unordered_map<int,int> mp;
//   int curr=0;

    for(int i=0; i<n; i++){
        mp[v[i]]+=nc2(n-i-1);
    }

    vector<pair<int,int>> res;

    for(auto x: mp){
       res.push_back({x.first, x.second});
    }
   sort(res.begin(), res.end());
    int m=v.size();
    for(int i=1; i<m; i++){
        res[i].second+= res[i-1].second;

    }

    while(q--){
        int r; cin>>r;
        
        int l=0; int h=m-1;

      int ans=0;
        while(l<=h){
            int mid=(l+h)/2;

            if(res[mid].second>=r && (mid==0 ? 1 : res[mid-1].second<r)){
                ans=res[mid].first;
                break;
            }

            else if(res[mid].second<r){
l=mid+1;
            }

            else{
                h=mid-1;
            }
        }
  cout<<ans<<endl;
    }

    return;
}

int32_t main(){
    int t; cin>>t;
    for(int i=0; i<t; i++)
    solve2();

    return 0;
}