/*
problem link->
https://codeforces.com/problemset/problem/1567/C
*/

#include <bits/stdc++.h>
using namespace std;

int number(int i, int mask, int arr[]){
    //returns number of ways to form an answer 
}

void solve(){
    int n; cin>>n;
    
    
    int ct=1;

   vector<int>odd,even;
   while(n>0){
    int rem=n%10;
    n/=10;
    if(ct%2){
        odd.push_back(rem);
    }
    else{
      even.push_back(rem);
    }
    ct++;
   }

   int a=0, b=0;
   while(odd.size()>0){
     a=a*10+odd.back();
     odd.pop_back();
   }
    while(even.size()>0){
     b=b*10+even.back();
     even.pop_back();
   }
   
   int ans=(a+1)*(b+1)-2;
    cout<<ans<<endl;
 



}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}