#include <bits/stdc++.h>
using namespace std;

const int mod= 1e9+7;


int n,k;
int ways;


int binexpo(int a, int b){

    if(b==1) return a;
    if(b==0) return 1;

    int temp=binexpo(a, b/2);
    temp=temp*temp%mod;
    if(b%2) temp*=a;
    return temp%mod;

}
int func(int i,  bool tight){

   if(i>k) return 1;

   if(tight){
      //tight hi rakho
   int res1=0;
   //1 kardo
    int op1=0;
    if(n%2)
    {
        op1=1;
    }

   //0 kardo
   int op2=0;
   if(n%2){
     op2=ways;
   }
   else{
     op2= ways*2-1;
   }

   res1=(op1+op2)*func(i+1, tight);

      //relax kardo
      int res2=0;
      if(n%2){
        res2=1;
        res2*= func(i+1, 1-tight);
      }
      else{
        res2=0;
      }


// cout<<"res1= " <<res1<<endl;
      return res1+res2;

   }

   else{
      int temp=func(i+1, tight);
      return (temp*binexpo(2,n))%mod;
   }
}

void solve(){
  
 cin>>n>>k;

  ways=0;

  int x=n;
 if(n%2) ways= binexpo(2,n-1);
 else ways= binexpo(2,n-2);


  ways%=mod;

  int ans=func(1,1);
  cout<<ans<<endl;

}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}