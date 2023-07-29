#include <bits/stdc++.h>
  using namespace std;

void solve(){
  int n; cin>>n;
 string s; cin>>s;


  map<int,int> mp;
  int x=0;set<int> st;
  
  for(int i=0; i<n; i++){
    // if(mp.find(s[i]-'a')!=mp.end()) mp[s[i]-'a']=x++;
    if(st.find(s[i]-'a')==st.end()){
      mp[x++]=s[i]-'a';
      st.insert(s[i]-'a');
    }
  }
  
  vector<int> v;
  
  for(auto x: mp){
    v.push_back(x.second);
  }
  
  sort(v.begin(), v.end());
  
  map<int,int> g;
  for(int i=0; i<v.size(); i++){
    g[mp[i]]=v[i];
  }
  
  //mapede
  
  string ans="";
  for(int i=0; i<n; i++){
    ans+= 'a' + g[s[i]-'a'];
  }
  
  cout<<ans<<endl;
}

  int main() {

  solve();

    return 0;

  }