/*
problem link ->
https://atcoder.jp/contests/arc159/tasks/arc159_b
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){

    int a,b;
    cin>>a>>b; int ans=0;
    while(min(a,b)!=0){
        ans++;
        int g=__gcd(a,b);
        a/=g; b/=g;
        a--, b--;
        
        if(a==1 || b==1){
            ans+=min(a,b);
            break;
        }
    }

    cout<<ans<<endl;

}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}