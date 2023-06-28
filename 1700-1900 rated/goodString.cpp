/*
problem link->https://codeforces.com/problemset/problem/1678/B2
*/

#include <bits/stdc++.h>
using namespace std;

int oddsum(vector<int> &v, int a, int b){
    int  sum=0;
    for(int i=a; i<=b; i+=2){
    sum+=v[i];
    }

    return sum;
}

int evensum(vector<int> &v, int a, int b){
    int sum=0;
    for(int i=a+1; i<=b; i+=2){
    sum+=v[i];
    }

    return sum;
}

void solve(){
    int n; cin>>n;
    string s; cin>>s;

    vector<int>v;
    int curr=1;
    for(int i=1; i<n; i++){
        if(s[i]==s[i-1]) curr++;

        else {
            v.push_back(curr);
            curr=1;
        }
    }

    v.push_back(curr);

    int m=v.size();
    vector<int> odd;
    int cc=0;
    bool flag=true;
    
    for(int i=0; i<m; i++){
        if(v[i]%2) {
            odd.push_back(i);
            flag=!flag;
        }
        else{
            flag && cc++;
        }
    }
    int operations=0;

    int o=odd.size();
   
    for(int i=0; i<o; i+=2){
      int op1=odd[i+1]-odd[i];
      int op2= oddsum(v,odd[i], odd[i+1]);
      int op3= evensum(v,odd[i], odd[i+1]);

      if(op1< op2 && op1<op3){
        cc+=odd[i+1]-odd[i];
        operations+= op1;
      }
      else{
        cc+=1;
        operations+=min(op2, op3);
      }
    }
    
      cout<<operations<<" "<<cc<<endl;
   
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}