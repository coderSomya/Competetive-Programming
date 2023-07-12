#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n,k; cin>>n>>k;
  int arr[n];
  map<int,int> ps;
  
  for(int i=0; i<n; i++) {
    cin>>arr[i]; ps[arr[i]]=i;
  }

  int curr=0;
  int pos,shift;

  for(int i=0; i<n; i++){
    int lesser= arr[i]-1;
    if(lesser>=k){
          int shift=ps[k];
          int pos=i;
          break;
    }
    int mid= n-i + (n-i-1)*(n-1-i);
    if(lesser+mid<k){
        int x=k-lesser-mid;

        int shift=ps[i+x];
        int pos=i;
        break;
    }

    k-=lesser+1;

  }

  //reverse from pos....shift

  int left=pos; int right=shift;
  while(left<right){
   swap(arr[left], arr[right]);
  left++; right--;
  }

  for(auto x: arr) cout<<x<<" ";
  puts("");

  
}

int main(){
    // int t; cin>>t;
    // while(t--) 
    solve();


    return 0;
}