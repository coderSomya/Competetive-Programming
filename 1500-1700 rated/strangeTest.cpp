/*
problem link->
https://codeforces.com/problemset/problem/1632/C
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e6;
int a,b; 

int pow2(int b, int lastb){
    for(int i=lastb+1; i>=0; i--) if(b&(1<<i)) return true;

    return false;
}

int convertB(){
    set<int> sa,sb;

    for(int i=0; i<=20; i++){
        if(a&(1<<i)) sa.insert(i);
        if(b&(1<<i)) sb.insert(i);
    }

    set<int> sx;

    for(auto x: sa){
        if(sb.find(x)==sb.end()) sx.insert(x);
    }

    int res=0;
    for(auto x: sx) res+=(1<<x);

    return res;

}


int convertA(){


    int lasta=-1; int lastb=-1;
    for(int i=20; i>=0; i--){    
        if((a&(1<<i)) && !(b&(1<<i))){
            lasta=i;
        } 
        if((b&(1<<i)) && !(a&(1<<i))){
            lastb=i;
        }
        if(lasta!=-1 && lastb!=-1) break;
    }
    int target=0;
  

    for(int i=20; i>=0;i--){
     if((a&(1<<i) && !( b&(1<<i))) || i==lastb){
        target+=(1<<i);
     }
     if(i==lastb) break;
    }
    

    int res=target- a;
    if(pow2(b,lastb)) res+=1;

    return res;

}
void solve(){
   cin>>a>>b;

   int temp1=b-a;
   int temp2=convertB();
   int temp3=convertA();

 

  cout<<temp1<<" "<<temp2<<" "<<temp3<<endl;
   cout<<min({temp1,temp2, temp3})<<endl;

}

int main(){
    int t; cin>>t;
    while(t--) solve();


    return 0;
}
