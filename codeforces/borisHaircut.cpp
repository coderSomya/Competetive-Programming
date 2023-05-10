/*
problem link->
https://codeforces.com/problemset/problem/1779/D
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    int a[n], b[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }

    int m; cin>>m;
    unordered_map<int,int> mp;
    for(int i=0; i<m;i++){
        int x; cin>>x;
        mp[x]++;
    }

    stack<int> st;
    for(int i=0;i<n; i++){
        if(a[i]<b[i]){
            cout<<"NO"<<endl;
            return;
        }
        if(st.empty() || st.top()>b[i]) st.push(b[i]);
        else{
            while(!st.empty() && st.top()<b[i]){
                int x=st.top();
                if(mp.find(x)==mp.end()){
                     cout<<"NO"<<endl;
                     return;
                }
                else{
                   st.pop();
                   mp[x]--;
                   if(mp[x]==0) mp.erase(x);
                }
            }

            // if(st.empty() ||(a[i]!=b[i] && st.top()!=b[i])) st.push(b[i]);
            if(st.empty()){
                  if(a[i]!=b[i]) st.push(b[i]);
            }
            else{
                if(st.top()!=b[i]) st.push(b[i]);
            }
        }
    }
    
    while(!st.empty()){
        int x=st.top();
        st.pop();
        if(mp.find(x)==mp.end()){
            cout<<"NO"<<endl;
            return;
        }
        mp[x]--;
        if(mp[x]==0) mp.erase(x);
    }
    cout<<"YES"<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}