#include <bits/stdc++.h>
using namespace std;


const int nax = 3005;

const int mod = 998244353;

int pref[nax];
int n;
string s;
vector<int>charges;

int ans=0;

void rec(int i, int plus_so_far){
   
   //calculate direction
    int charge_on_left= 2*plus_so_far - i;
    int charge_on_right= 2*(n-plus_so_far-1) - (n-1-i);
   if(s[i]=='+'){
      

      if(charge_on_left- charge_on_right > 0){
        //direction = +
        charges.push_back(i);
        return rec(i+1, plus_so_far+1);
      }
      else{
         int x= charges.back();
         charges.pop_back();
         ans+=2*((i-x+1)/2);
         return rec(i+1, plus_so_far+1);
      }
   }


   if(s[i]=='-'){
      
      if(charge_on_left>charge_on_right){
        //direction = -

        int x= charges.back();
        charges.pop_back();
        ans+= (2*(i-x+1))/2;
        return rec(i+1, plus_so_far);
      }
      else{
        charges.push_back(i);
      }
   }
}


void solve(){

    cin>>n;
    cin>>s;

}

int main()
{
   solve();
   return 0;
}