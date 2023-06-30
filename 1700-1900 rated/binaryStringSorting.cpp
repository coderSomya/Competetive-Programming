#include <bits/stdc++.h>
using namespace std;

const long long VAL=1e12;

void solve(){
    string s; cin>>s;
   int n=s.length();

    long long cost =0;       

   cout<<cost<<endl;
}

long long rec_brute(int i, int zeroes, vector<pair<int,int>> &v){
    if(i<0) return 0;
    
    if(v[i].first==0){
        return min(rec_brute(i-1, zeroes+v[i].second, v), v[i].second*(VAL+1)+ rec_brute(i-1, zeroes, v));
    }

    else return min((VAL+1)*v[i].second + rec_brute(i-1, zeroes, v), v[i].second*(zeroes)*(VAL) + rec_brute(i-1, zeroes, v));

}

void brute(){
    string s; cin>>s;
    int n=s.length();

    long long  cost=0;

  vector<pair<int,int>>v;
  v.push_back({s[0]-'0', 1});
  for(int i=1; i<n; i++)
  {
    if(s[i]==s[i-1]) v.back().second++;
    else v.push_back({s[i]-'0', 1});
  }

  int m=v.size();

cost = rec_brute(m-1, 0, v);



    cout<<cost<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) brute();

    return 0;

}