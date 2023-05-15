#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve(){
   
   int n;cin>>n;
   int arr[n];
   int zeroes=0;
   for(int i=0; i<n; i++) {
    cin>>arr[i];
    zeroes+=arr[i]==0;
   }

   int pref[n];
   pref[0]=arr[0]==0;
   for(int i=1;i<n; i++) pref[i]=pref[i-1]+(arr[i]==0);

   //find subarrays with zero sum and not containing a zero in between
   unordered_map<int,int>mp;
   mp[0]=-1;
   int sum=0;
   int extra=0;
   for(int i=0; i<n; i++){
    sum+=arr[i];
    if(arr[i]!=0 && mp.find(sum)!=mp.end()){
        if(pref[i]-pref[mp[sum]+1]==0) extra++;
    }
    mp[sum]=i;
   }
   
   int ans=pref[n-1]+extra;
  
   cout<<ans<<endl;

}

int32_t main(){
    int t; cin>>t;
    while(t--) solve();


    return 0;
}