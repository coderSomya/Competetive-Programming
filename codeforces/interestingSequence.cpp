/*
problem link ->
https://codeforces.com/problemset/problem/1775/C
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int>pow2;

void solve(){
    int n, x;
    cin>>n>>x;


    vector<int> first(61);
    vector<int> second(61);
    int p=x;

    for(int i=0; i<=60; i++){
        if(n&1) {
            first[i]=1;
        }
        else first[i]=0;

        if(x&1){
            second[i]=1;
        }
        else second[i]=0;
        n/=2; x/=2;

    }


    int last=-1;
    bool flag=false;
    
    for(int i=0; i<=60; i++){
     if(first[i]==1 && second[i]==1){
         flag=true;
     }
     if(first[i]==0 && second[i]==0){
         continue;
     }
     if(first[i]==1 && second[i]==0){
       if(flag){
        cout<<-1<<endl;
        return;
       }
       else{
        last=i;
       }
     }
     if(first[i]==0 && second[i]==1){
      cout<<-1<<endl;
      return;
     }
    }
    

    if(last==-1){
        cout<<p<<endl;
    }
    else{
        cout<<p+pow2[last+1]<<endl;
    }
}


int32_t main(){
    int t; cin>>t;
    pow2.push_back(1);
    for(int i=1; i<=61; i++){
     pow2.push_back(pow2.back()*2);
    }

  
    while(t--) solve();

    return 0;
}


