/*
problem link->
https://codeforces.com/problemset/problem/1628/B
*/

#include <bits/stdc++.h>
using namespace std;


void solve(){
   
   int n;
   cin>>n;
   unordered_map<string, vector<int>> s1;
   unordered_map<string, vector<int>> s3;
   unordered_map<string, vector<int>> s2;

//    cout<<"befrore"<<endl;

   for(int i=0; i<n; i++){
    string s; cin>>s;
    int x=s.length();
    if(x==1) {

        s1[s].push_back(i);
    }
    if(x==2) {
        s2[s].push_back(i);
    }
    if(x==3) {
        s3[s].push_back(i);
    }
   }

    //   cout<<"sfter"<<endl;
  
  //order matters;
   if(s1.size()>0){
    cout<<"YES"<<endl;
    return;
   }
   
   for(auto s: s2){
    string candi=s.first;
    
    reverse(candi.begin(), candi.end());
    if(s2.find(candi)!=s2.end())
    {
        cout<<"YES"<<endl;
        return;
    }
   }

   for(auto s: s3){
    string candi=s.first;
    
    //cb+ abc
    string check="";
    check+=candi[2];
    check+=candi[1];
    if(s2.find(check)!=s2.end()){
        if(s2[check][0]<s.second.back()){
            cout<<"YES"<<endl;
            return;
        }
    }
   
   //abc+ba
    string check2="";
    check2+=candi[1];
    check2+=candi[0];
    if(s2.find(check2)!=s2.end()){


     if(s2[check2].back()>s.second[0]){
            cout<<"YES"<<endl;
            return;
        }
    }

    reverse(candi.begin(), candi.end());
    if(s3.find(candi)!=s3.end()){
        cout<<"YES"<<endl;
        return;
    }
   }

   cout<<"NO"<<endl;

}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}