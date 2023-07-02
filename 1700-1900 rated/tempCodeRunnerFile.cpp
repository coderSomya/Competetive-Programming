#include <bits/stdc++.h>
using namespace std;

int query(int x){
    cout<<"- "<<x<<endl;
    int res; cin>>res;
    return res;
}

void solve(){
    int prev; cin>>prev;
    int val=0;

    for(int i=0; i<30; i++){
        if(prev==0) break;
        int x = (1<<i);
        int cnt=query(x);
        if(cnt==prev){
           //0 tha; 
           continue;
        }

        assert(cnt==prev-1);
        prev=cnt;
        val+=(1<<i);

    }


    cout<<"! "<<val<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();


    return 0;
}