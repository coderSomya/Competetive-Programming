//codechef long challenge

#include <bits/stdc++.h>
using namespace std;

int binpow(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    int res=binpow(a,b/2);
    res*=res;
    if(b%2) res*=a;

    return res;
}

int cnt(string &s, int n, int tight){
    if(n==0) return 1;

    if(!tight) return binpow(10,n);

    int ub=tight? s[s.length()-n]-'0': 9;
    int answer=0;

    for(int dig=0; dig<=ub; dig++){
       answer+= cnt(s,n-1,tight&(dig==ub));
    }

    return answer;
}

int solve(string &s, int n, int tight, int prev){
   
   if(n==0) return 0;
   
   int len=s.length();
   int ub=tight? s[len-n]-'0':9;
   int total=0;

   for(int i=0; i<=ub; i++){
       if(i==prev) total+= solve(s,n-1,tight&(i==ub), prev);

       else total+= i*binpow(10,n-1)*cnt(s,n-1,tight&(i==ub)) + solve(s,n-1,tight&(i==ub), i);
   }

}

int main(){
    
    string s; cin>>s;

    solve(s,s.length(), 1, -1);

}