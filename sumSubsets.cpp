#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e6;
const int MAXLOG=20;

void solve(){
    
    int n;
    cin>>n;
    int arr[n];
    int forward1[MAXN]={0};
    int forward2[MAXN]={0};
    for(int i=0; i<n; i++){
        cin>>arr[i];
        forward1[arr[i]]++;
        forward2[arr[i]]++;
    }

    

    
    for(int i=0;i<=MAXLOG; i++){
        for(int j=0;j<MAXN; j++){
         if(j&(1<<i)) {
            forward1[j]+=forward1[j^(1<<i)]; //adding value of subsets to the super set
         }
        }
    }

      for(int i=0;i<=MAXLOG; i++){
        for(int j=MAXN-1;j>=0; j--){
         if(j&(1<<i)) {
            forward1[j^(1<<i)]+=forward1[j]; //adding value of supersets to the subset
         }
        }
    }

    //problem find all super sets of zero
    // cout<<forward2[0]<<endl;


}

int main(){
    int t; cin>>t;
  
  for(int i=0;i<t;i++) solve();

    return 0;
}
