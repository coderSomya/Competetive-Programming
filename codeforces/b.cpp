#include <bits/stdc++.h>
using namespace std;


int dp[13][1<<13][13][13];

int rec(int i, int mask, int h, int sh, int n, vector<vector<int> > &v){
    cout<<mask<<endl;
    if(i==n){
        return (h==n) || (sh>=1);
    }
    
    int temp=0;
    
    if(dp[i][mask][h][sh]!=-1) return dp[i][mask][h][sh];
    
    for(int bit=0; bit<n; bit++){
        // cout<<mask<<" "<<(1<<bit)<<" "<<mask&(1<<bit)endl;
       if((mask&(1<<(bit))) == 0)  {
           
           int temp_mask= mask+(1<<(bit));
        //    cout<<"temp"<<temp_mask<<endl;
           int nh=h; int nsh=sh;
           if(v[i][bit]==2) nh++;
           else if(v[i][bit]==3) nsh++;
           
           temp+=rec(i+1,temp_mask, nh, nsh, n, v);
       }
    }
    
    return dp[i][mask][h][sh] = temp;
}

void solve()
{   
    
    int A=5;
    vector<vector<int>> B={
        {1,1,3,2,3}, {3,3,3,3,3}, {2,3,1,1,3},{2,2,2,1,2},{2,1,1,2,1}
    };

      memset(dp, -1, sizeof(dp));
    
    long ans=long(rec(0,0,0,0,A,B));
    
    cout<<ans<<endl;
    
}

int main(){
    solve();
    return 0;
}