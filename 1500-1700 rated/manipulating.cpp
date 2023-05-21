/*
problem link ->
https://codeforces.com/problemset/problem/1688/C
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    int freq[26]={0};

    for(int i=0;i<=2*n; i++){
        string s; cin>>s;
        for(char ch: s) freq[ch-'a']++;
    }

    for(int i=0; i<26; i++) if(freq[i]%2){
       cout<<(char)('a'+i)<<endl;
       return;
    }
}


int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}