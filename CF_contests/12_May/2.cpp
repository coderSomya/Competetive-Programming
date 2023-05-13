#include <bits/stdc++.h>
using namespace std;

/*
codeforces contest after a while, lessgo..
*/

/*
pupil tonight..
*/

void solve(){
    string s;cin>>s;

   int n=s.length();
   set<char> st;
   for(int i=0; i<n/2;
   i++){
    st.insert(s[i]);
   }

   if(st.size()>1){
    cout<<"YES"<<endl;
   }
   else{
    cout<<"NO"<<endl;
   }
}


int main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}