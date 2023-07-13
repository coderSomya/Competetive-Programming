#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n; cin>>n;
    // int a[n], b[n];
    vector<int> a(n), b(n);

    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    vector<int> pos;
    vector<pair<int, pair<int,int>>> neg;

    for(int i=0; i<n; i++){
        int x=a[i]+b[i];
        if(x>=0) pos.push_back(x);

        else{
            neg.push_back({x, {a[i], b[i]}});
        }
    }


    sort(rbegin(pos), rend(pos));
    sort(begin(neg), begin(neg));


    int m=(int)pos.size();

    int pref[m];
    pref[0]=pos[0];
    for(int i=1; i<m; i++) pref[i]=pref[i-1]+pos[i];

    if(neg.empty()){
       cout<<pref[m-1]<<endl;
       return;
    }


    if(pos.empty()){
        vector<int> v;
        for(int i=0; i<b.size(); i++){
           if(neg[i].second.first>=0)v.push_back(neg[i].second.first);

           if(neg[i].second.second>=0) v.push_back(neg[i].second.second);
        }

        sort(v.rbegin(), v.rend());

        if(v.size()==0){
            cout<<0<<endl;
            return;
        }
        if(v.size()==1 || v.size()==2) {
            cout<<v[0]<<endl; return;
        }
        if(v.size()>=3){
            cout<<max(v[0], v[1]+v[2])<<endl;
            return;
        }
    }


    //neither are empty

    //pos[0] pos[1] pos[2] -4 -5 pos[3] pos[4] pos[5]

    //pos[0] pos[1] pos[2] -5 -4 pos[3] pos[4]

    //pos[0] pos[1] pos[2] -4 -5 pos[3] pos[4]

   //pos[0] pos[1] pos[2] 1 -6 pos[3] pos[4] pos[5]
  int ans=0;
//case work

   

}

int main(){
    int t; cin>>t;
    while(t--) solve();


    return 0;
}