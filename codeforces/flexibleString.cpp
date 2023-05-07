/*
problem link ->
https://codeforces.com/problemset/problem/1778/C
*/

#include <bits/stdc++.h>
using namespace std;

string s1,s2;
int n,k;
int ans;
unordered_map<char, int> mp; 

void check(int mask){
    cout<<mask<<endl;
   int last=0;
   int temp=0;
   for(int i=0; i<n; i++){
     if(s1[i]==s2[i] || mask&(1<<mp[(s1[i]-'a')])) temp+=i-last+1;
     else last=i+1;
   }

   ans=max(ans, temp);

   if(temp==10){
    cout<<mask<<endl;
     for(int i=0; i<n; i++){
     if(s1[i]==s2[i] || mask&(1<<mp[(s1[i]-'a')])) {
        cout<<s1[i]<<" "<<s2[i]<<endl;
     }
     else {
        cout<<s1[i]<<" "<<s2[i]<<endl;
     }
   }
   }
}

int total;

//maps characters to 10 different numbers
void count(int i,int mask){
//    cout<<mask<<endl;
   //generate all masks possible
   
   int bits=__builtin_popcount(mask);
    if(i>=total) return;
   if(bits==k){
    check(mask);
    return;
   }
   count(i+1, mask);
   count(i+1, mask|1<<(i+1));

//   cout<<ans<<endl;
  

}

void solve(){
    cin>>n>>k;
    cin>>s1;
    cin>>s2;
    mp.clear();
    int rr=0;
    for(int i=0; i<n; i++){
        if(mp.find(s1[i])==mp.end()){
            mp[s1[i]]=rr;
            rr++;
        }
    }
    total=rr;
    count(0,0);
    count(0,1);

    cout<<ans<<endl;
}

int main(){
    int t; cin>>t;

    while(t--) solve();

    return 0;
}