#include <bits/stdc++.h>
using namespace std;

void solve(){
   
   int n,m; cin>>n>>m;

   int arr[m];

   int base=0;
   int sum=0;

   for(int i=0; i<m; i++){
      cin>>arr[i];
      if(arr[i]==n) base++;
      else sum+=arr[i];
   }


   int rem= sum%n;
   if(rem==0){
    if(sum/n + base == m)
    {
        cout<<n<<endl;
    }
    else cout<<0<<endl;
   }

   else{
    if(1+ sum/n + base == m){
      cout<<rem<<endl;
    }
    else cout<<0<<endl;
   }
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}