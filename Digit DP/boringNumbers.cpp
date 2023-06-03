//Google kickstart 2020 problem

//boring number has odd digits in odd places and even digits in even places

/*
dp(n,even,leading,tight)->number of n digit numbers with constraint on first(tight), am i continuing with leading zeroes and am i in an even position
*/

#include <bits/stdc++.h>
using namespace std;

int solve(string &s,int n, bool even,bool leading, int tight){

    if(n==0)return 1;
    int len=s.length();
    int ans=0;
    int ub=(tight)?(s[len-n]-'0'):9;

    if(even){
        vector<int> digits={0,2,4,6,8};
       

        for(auto dig: digits){
            if(dig<=ub) ans+=(s,n-1,0,0,tight&(dig==ub));
        }
    }

    else{
        vector<int> digits={1,3,5,7,9};

        if(leading==1){
            //continue with more leading zeores
          ans+=solve(s,n-1,0,1,0);
        }
      //put our first non-zero digit
      for(auto dig: digits){
        if(dig<=ub) ans+=(s,n-1,1,0,tight&(dig==ub));
      }
    }

    return ans;

    
}


int main(){
    long long l,r; cin>>l>>r;
    l--;
    string a,b;
    a=to_string(l); b=to_string(r);
     
    int res=solve(b,b.length(),0,1,1);
    res-=solve(a,a.length(),0,1,1);

    cout<<res<<endl;
}

