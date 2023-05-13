/*
problem link ->
https://codeforces.com/problemset/problem/1744/E1
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    unordered_map<int,int> mp;
    int x=a*b;
    for(int i=a+1; i<=c; i++){
        int beta=x/__gcd(x,i);
        mp[beta]=i;
    }

    for(int i=b+1; i<=d; i++){
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                if(mp.find(j)!=mp.end()){
                    //got a pair
                    cout<<mp[j]<<" "<<i<<endl;
                    return;
                }

                if(mp.find(i/j)!=mp.end()){
                    cout<<mp[i/j]<<" "<<i<<endl;
                    return;
                }
            }
            
        }
    }

    cout<<-1<<" "<<-1<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}