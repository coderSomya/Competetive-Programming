#include <bits/stdc++.h>
using namespace std;

int n; 
int arr[20];

int maxi;

void count(string &s){

    // cout<<s<<endl;

    int help[n];

    help[0]=arr[0];
    for(int i=1; i<n-1; i++){
        if(s[i]=='1'){
            if(help[i-1]%2==0 && arr[i+1]%2==0){
                help[i]=(help[i-1]+arr[i+1])/2;
            }
            else help[i]=arr[i];
        }
        else help[i]=arr[i];
    }

    help[n-1]=arr[n-1];
    int temp=0;
    for(int i=0; i<n; i++){
         if(i<n/2) temp+=help[i];
         else if(i==n/2){
              if(n%2) continue;
              else temp-=help[i];
         }
         else temp-=help[i];
    }

    // cout<<abs(temp)<<endl;

    maxi=max(maxi, abs(temp));
}

 void rec(int i, string &s){
   if(i==n){
    count(s); return;
   }

   else{
    string s1,s2;
    s1=s2=s;
    s1+='1';
    s2+='0';
    rec(i+1,s1);
    rec(i+1,s2);
   }
 }


void solve(){
   cin>>n;
   maxi=-1e8;

   for(int i=0; i<n; i++)cin>>arr[i];
   string s="";

   rec(0,s);
   cout<<maxi<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}