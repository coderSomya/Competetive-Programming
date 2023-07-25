#include <bits/stdc++.h>
using namespace std;

int check(int a, int arr[], int val, int n){
   
   int maxi= val-a;
   int l=0; int h=4*n-1;
   int ans=4*n;

   while(l<=h){
    int mid= (l+h)/2;

    if(arr[mid]>maxi){
        h=mid-1;
    }
    else{
        ans=mid;
        l=mid+1;
    }
   }

   return ans;

}

bool bs(int times[], int task[], int val, int n){

    vector<int> v(4*n, 0);

    for(int i=0; i<n; i++){
        int idx= check(times[i], task, val, n);
        if(idx==4*n){
            return false;
        }
        else v[idx]++;
    }

    int curr=0;
    for(int i=0; i<4*n; i++){
        if(v[i]==0) curr++;

        else{
            if(3*v[i]>curr) return false;
            else curr-= 3*v[i];
        }
    }

    return true;
}

void solve(){
    int n; cin>>n;
    int times[n], task[4*n];

    for(int i=0; i<n; i++) {
        cin>>times[i]; }
    for(int i=0; i<4*n; i++) cin>>task[i];

    sort(task, task+4*n);
    sort(times, times+n);

    int l= task[0]+times[0];
    int h= task[4*n-1]+times[n-1];

    int ans=0;
    while(l<=h){
        int mid= (l+h)/2;

        if(bs(times, task, mid, n)){
            ans=mid;
            h=mid-1;
        }
        else l=mid+1;
    }
  cout<<ans<<endl;
    

}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}