/*
problem link ->
https://codeforces.com/problemset/problem/1772/E
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    int arr[n+1];
    int a,b,c;
    a=b=c=0;
    for(int i=1;i<=n; i++){
        cin>>arr[i];
        if(arr[i]!=i) a++;
        if(arr[i]!=n+1-i) b++;
        if((arr[i]!=n+1-i && arr[i]!=i))c++;
    }
    
  
    if(a+c<=b) cout<<"First"<<endl;
    else if(b+c<a) cout<<"Second"<<endl;

    else cout<<"Tie"<<endl;
}

int main(){

    int t; cin>>t;
    while(t--) solve();

    return 0;

}