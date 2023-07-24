#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<int,int>, int> &a, pair<pair<int,int>, int> &b)
{
    if(a.first.first<b.first.first) return true;

    if(a.first.first==b.first.first) return a.first.second>=b.first.second;

    return false;
}

void solve(){

    int n; cin>>n;
    
    vector<pair<pair<int,int>, int>> v;

    for(int i=0; i<n; i++){
        int u,p; cin>>u>>p;
       v.push_back(make_pair(make_pair(u,p), i+1));
        
    }

    sort(v.begin(), v.end(), cmp);
 vector<int> bad;
    for(int i=0; i<n-1; i++){
        if(v[i].first==v[i+1].first){
            bad.push_back(i+1);
        }
    }
    int last=0;
   

    for(int i=0; i<n; i++){
        if(v[i].first.second>last){
            last=v[i].first.second;
            continue;
        }

        

        bad.push_back(v[i].second);
    }

    cout<<(int)bad.size()<<endl;

    for(auto x: bad) cout<<x<<endl;
    
}

int main(){
    solve();

    return 0;


}