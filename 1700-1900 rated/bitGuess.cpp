#include <bits/stdc++.h>
using namespace std;

int query(int x){
    cout<<"- "<<x<<endl;
    int res; cin>>res;
    return res;
}

void solve(){
    int prev; cin>>prev;
    int val=0; int x=1;

    while(prev!=0)
    { 
        int cnt=query(x);
        if(cnt==prev-1){
            //ynha pe 1 tha;
            val+=x;
            prev=cnt;
        }
        else{
        int m=cnt-prev;

        //ynha se leke agle m bits set hain;
        int p=x;
        int bit=log2(p);
        for(int i=1; i<=m; i++){
            p+=(1<<(bit+i));
        }
        int _ = query(p);
        prev=_;
        x=x<<m;
        val+=2*x;
        }

        x=x<<1;  
    }


    cout<<"! "<<val<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();


    return 0;
}