#include <bits/stdc++.h>
  using namespace std;
  
  bool check(string a, int x){
    
    string f= a.substr(0,x);
    int i=x;
    int n=a.length();
    while(i<n)
    {
      string temp=a.substr(i,x);
      if(f==temp) i+=x;
      else{
        return false;
      }
    }
    
    return true;
  }

string solve(string s1, string s2){
  
  int n=s1.length();
  int m= s2.length();
  
  set<int> a,b,c;
  
  for(int i=1; i*i<=n;i++){
    if(n%i==0){
      a.insert(i);
      if(i*i!=n){
        a.insert(n/i);
      }
    }
  }
  
  
  for(int i=1; i*i<=m; i++){
    if(m%i==0){
      b.insert(i);
      if(i*i!=m) b.insert(m/i);
    }
  }
  
  
  for(auto x: a){
    if(b.count(x)!=0) c.insert(x);
  }
  
  
  if(c.empty()) return "";
  
  string t= s1+s2;
  
  int ans=0;
  
  for(auto x: c){
    if(check(t, x)){
      ans=max(ans, x);
    }
  }
  
  string res= s1.substr(0,ans);
  return res;
}

  int main() {

    string s1, s2; cin>>s1>>s2;
    
    string s= solve(s1, s2);
    cout<<s<<endl;
    
    return 0;

  }