#include <bits/stdc++.h>
using namespace std;

#define loop(i,l,r) for(int i=l; i<r; i++);
#define pb push_back


//binary search

void solve(){
    int n; cin>>n; 
    int arr[n]; 
    for(int i=0; i<n; i++) cin>>arr[i];

    vector<int> ans;
    ans.pb(arr[0]);
    for(int i=1; i<n; i++){
     if(arr[i]>ans.back()) ans.pb(arr[i]);
     else{
        int id= lower_bound(ans.begin(), ans.end(), arr[i])-ans.begin();
        ans[id]=arr[i];
     }
    }

   cout<<ans.size()<<endl;

}

int main(){

    int t; cin>>t; while(t--) solve();
    return 0;
}