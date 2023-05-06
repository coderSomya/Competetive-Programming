#include <bits/stdc++.h>
using namespace std;

set<int> st;
const int inf= 1e9+10;
void fill_factors(int n){

    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            st.insert(i);
            st.insert(n/i);
        }
    }
}
void solve(){

    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int mini=inf;
    int t=-1;
    set<int> s;
    for(int i=0; i<=n/2; i++){
        if(arr[i]!=arr[n-1-i]){
            s.insert(i);
            mini=min(mini, abs(arr[i]-arr[n-1-i]));
        }
    }

    if(s.size()==0){
        cout<<0<<endl;
        return;
    }

    fill_factors(mini);
    //O(sqrt(a[i]))
   for(auto x: s){
     for(auto y: st){
        if(arr[x]%y !=arr[n-1-x]%y) st.erase(y);
     }
   }

   if(st.size()==0){
    cout<<1<<endl;
    return;
   }
   int ans=0;

   for(auto x: st){
    ans =max(ans, x);
   }

   cout<<ans<<endl;

    
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}