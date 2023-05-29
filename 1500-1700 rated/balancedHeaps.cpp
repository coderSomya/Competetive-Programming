/*
problem link->
https://codeforces.com/problemset/problem/1623/C
*/

#include <bits/stdc++.h>
using namespace std;

const int N= 1e9;

bool possible(vector<int> &arr, int k){
   
   vector<int> test(arr);
   int n=test.size();
   //at ith step, try to satisfy (i-2)th item;

   //check for the first triad;

   int y=max(0, k-test[0]);
   y+= y%2;
   test[0]+=y;
   test[1]+=y/2;
   test[2]-=3*y/2;

   if(test[2]<0) return false;

for(int i=3; i<n; i++){
    
    int x=max(0, k-test[i-2]);
  //get from i-1
   
   //to get r from i-1, i-1 has to spend 3*r
    test[i-2]+=min(x,test[i-1]);
    test[i-1]-=min(x,test[i-1]);

    int rem=max(0,(k-test[i-2]));
    rem+=rem%2;
    test[i-2]+=rem;
    test[i-2]+=rem/2;
    test[i]-=3*rem/2;

    if(test[i]<0){
    return false;
    }
   }

   //check for n-1,n-2
   
   if(test[n-1]<k) return false;
   if(test[n-2]+test[n-1]<2*k) return false;
 
   return true;   
}
void solve(){
    int n; cin>>n;
   vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    int l=0; int h=N;

    //binary search on answer
    int ans=-1;

    while(l<=h){
        int mid=(l+h)/2;

        if(possible(arr, mid)){
            // cout<<"mid is "<<mid<<endl;
            ans=mid;
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }

    cout<<ans<<endl;

}


int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}