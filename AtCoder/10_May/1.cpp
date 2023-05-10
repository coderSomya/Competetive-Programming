#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        if(x%2==0) v.push_back(x);
    }

    for(auto x: v) cout<<x<<" ";
    cout<<endl;
}

int main(){
    // int t; cin>>t;
    // while(t--)
     solve();

    return 0;

}