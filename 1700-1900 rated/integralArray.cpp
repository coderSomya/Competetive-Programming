#include <bits/stdc++.h>
using namespace std;

void solve(){

   int n,c; cin>>n>>c;
   int arr[n];
   unordered_set<int> st;  
   unordered_set<int> ast;  
   for(int i=0; i<n; i++){
    cin>>arr[i];
    st.insert(arr[i]);
   }
  sort(arr, arr+n);
   if(st.find(1)==st.end()){
    cout<<"NO"<<endl;
    return;
   }

   int maxi=arr[n-1];
 ast.insert(1);
   for(int i=0; i<n; i++){
      if(arr[i]==1) continue;

      int temp=maxi;

      while(temp>=1){ 
        if(st.find(temp)==st.end()){
            cout<<"NO"<<endl;
            return;
        }
        ast.insert(temp);
        temp=temp/arr[i];
      }
   }
  if(ast.size()!=st.size()){
    cout<<"NO"<<endl;
    return;
  }
   cout<<"YES"<<endl;
}


int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}