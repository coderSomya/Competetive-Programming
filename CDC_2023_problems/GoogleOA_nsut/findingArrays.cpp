//google nsut


#include <bits/stdc++.h>
using namespace std;

int SUM;
const int mod= 1e9+7;

int n;

#define int long long 

vector<int> dig(105);

int count(int n){

    int res=0;
    while(n>0){
        int rem= n%10;
        res+=rem;
        n/=10;
    }

    return res;
}

int dp[102][1000];

int rec(int curr, int last){
   

   int temp=0;

   if(curr<0) {
    // cout<<last<<endl;
    return 1;
   }

   if(dp[curr][last]!=-1) return dp[curr][last];

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
             int me=0;
             me+= i*100+ j*10;

             int digit_sum= i+j;
             int req= dig[curr]-digit_sum;
             if(req<0 || req>9) continue;
             
             me+= req;
           
             if(me>=last) continue;
           
            assert(i+j+req== dig[curr]);

            // cout<<i<<" "<<j<<" "<<req<<endl;
            
             temp+= rec(curr-1, me);
             if(dig[i]==1) {
                if(1000<last) temp+=rec(curr-1, 1000);
             }
        }
    }

    return dp[curr][last] = temp;
}

void solve(){
    cin>>n;

    int arr[n+1];
   
    for(int i=0; i<n; i++){
        cin>>arr[i]; 
    }   

    int ans=0; 

    dig.clear();
    dig.resize(n+1);

    for(int i=0; i<n; i++){
        dig[i]=count(arr[i]);
    }

    memset(dp, -1, sizeof(dp));
  
    ans+= rec(n-1, 1e3+1);

    cout<<ans<<endl;
    
}

int32_t main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}

