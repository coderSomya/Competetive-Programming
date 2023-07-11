#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
  vector<int> bad;
    for(int i=0; i<n; i++){
       for(int j=i+1; j<n; j++)
       {
            if(v[j]<=v[i])
            {
                bad.push_back(i);
                break;
            }
       }
    }


    cout<<n-(int)bad.size()<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}