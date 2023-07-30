#include <bits/stdc++.h>
using namespace std;

void solve(){
    int k; cin>>k;
    int n; cin>>n;
    long long arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
   int maxi=-1;
   int val=0;
    for(int i=0; i<n; i++){
        int ct=0;
        int m=arr[i];
        while(m){
            int rem=m%10;
            ct+= (rem==k);
            m/=10;

        }

        if(ct>maxi){
            maxi=ct;
            val=arr[i];
        }
    }
    cout<<val<<endl;
}
int main(){
  solve(); return 0;
}