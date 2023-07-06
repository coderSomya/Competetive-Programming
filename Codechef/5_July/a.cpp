#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin>>n; string s; cin>>s;
    int pref[n];
    unordered_map<char,int> mp;
    mp['(']=-1;
    mp[':']=0;
    mp[')']=1;
    pref[0]=mp[s[0]];
    vector<int> v;
    if(mp[s[0]]==0) v.push_back(0);
  
    for(int i=1; i<n; i++){
        pref[i]=pref[i-1]+mp[s[i]];
        if(mp[s[i]]==0) v.push_back(i);
    }
    int ans=0;
    for(int i=1; i<v.size(); i++){
        if(v[i]-v[i-1]>1 && pref[v[i]]-pref[v[i-1]]==v[i]-v[i-1]-1) ans++;
    }
   
    
    cout<<ans<<endl;
    
    
}

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--) solve();
	
	return 0;
}
