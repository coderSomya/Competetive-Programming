#include <bits/stdc++.h>
using namespace std;

#define int long long


int fact(int n){
    if(n==0) return 1;

    return n*fact(n-1);
}

void solve(){
    
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    int ans=n;

    for(int i=1; i<n; i++){
        // int temp=0;
         for(int j=i+1; j<n; j++){
            //i....j
            int temp=0;
            if(v[i]!=v[j])continue;
            vector<int> vv(n, 0);
            int ct=(v[i]!=0);
            int a,b; a=b=0;
            for(int k=i+1; k<j; k++){
                a+= v[k]>0;
                b+= (v[k]==0);
                if(v[k]>0) ct++;
            }

            temp=n-ct;
            temp*=fact(a);          
            temp*=fact(b);

            ans+= temp;
         }
    }


    cout<<ans<<endl;

}

int32_t main(){
    solve();

    return 0;
}