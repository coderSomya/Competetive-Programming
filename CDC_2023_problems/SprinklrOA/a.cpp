#include <bits/stdc++.h>
using namespace std;


const int N = 1e5;
#define int long long
const int mod = 1e9+7;

int32_t main() {
    
    bool prime[N + 1];
    memset(prime, true, sizeof(prime));
    vector<int> primes;
  
    for (int p = 2; p * p <= N; p++) {
       
        if (prime[p] == true) {
          primes.push_back(p);
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }

    
    int n; cin>>n;
    map<int, int> mp;

    int arr[n]; for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

  long long dp[n][65]= {0};
  

  int ct=0;

  for(int i=0; i<n; i++){
    for(int j=0; j<65; j++){
//  if(arr[i]%primes[j]!=0) continue;
        if(arr[i]%primes[j]==0 && arr[i]/primes[j]>0 && mp.find(arr[i]/primes[j])!=mp.end()){
           dp[i][j]=1+dp[mp[arr[i]/primes[j]]][j];
        }
        if(arr[i]==primes[j]) ct++;
    }
     mp[arr[i]]=i;
  }
  int ans=0;
  for(int i=0; i<n; i++){
 for(int j=0; j<65; j++) ans+= dp[i][j];
  }

//   ans-=ct;

  cout<<ans%mod<<endl;

    return 0;

  }