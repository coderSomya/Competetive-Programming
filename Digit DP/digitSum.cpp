/*
sum of sum of digits of all numbers from L...R
*/

#include <bits/stdc++.h>
using namespace std;

int binpow(int a,int b){
    if(b==0) return 1;

    if(b==1) return a;

    int res=binpow(a,b/2);
    res*=res;
    if(b%2) res*=a;

    return res;
}

int count(string &s, int n, int tight){
    if(tight) {
        if(n==0) return 0;

        int ub=tight? s[s.length()-n]:9;
        int numbers=0;
        for(int dig=0; dig<=ub; dig++){
            numbers+= count(s,n-1,tight&(dig==ub));
        }

        return numbers;
    }

    else return binpow(10,n);
}

int solve(string &s, int n, int tight){
    
    //return no.of numbers and sum of numbers 
    if(n==0) return 0;
    
    int len=s.length();
    int ub=(tight)? s[len-n]:9;
    int num=0, sum=0;

    for(int i=0; i<=ub; i++){
       sum+= i*count(s,n,tight&(i==ub));
       sum+= solve(s,n-1,tight&(i==ub));
    }

    return sum;


}

int main(){
    
    long long l,r;
    cin>>l>>r;
    l--;
    string s1=to_string(l);string s2=to_string(r);


    return 0;
}