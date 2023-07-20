#include <bits/stdc++.h>
using namespace std;


const int N = 2002; 
int n;
vector<int> arr(N);
vector<int> cost(N);
int k;

unordered_map<int,int> mini;

int dp[N][N];

int rec(int i, int num, vector<int> &pref_cost, vector<int> &pref_val){


    //dp[i][num] = (pref_val[i]+ k*num)*(pref_cost[i] - pref_cost[j-1]) + dp[j][num-1]

    
}

void solve()
{
   cin>>n; cin>>k;
   for(int i=0; i<n; i++) cin>>arr[i];
   for(int i=0; i<n; i++) cin>>cost[i];

   mini.clear();
  memset(dp, -1, sizeof(dp));

  vector<int> pref_val(n,0);
  vector<int> pref_cost(n, 0);

  pref_val[0]=arr[0];
  for(int i=1; i<n; i++) pref_val[i]=pref_val[i-1]+arr[i];

  pref_cost[0]=cost[0];
  for(int i=1; i<n; i++) pref_cost[i]=pref_cost[i-1]+cost[i];



}

int main()
{
    int t; cin>>t;
    while(t--) solve();

    return 0;
}

/*


 + 

=(a[1]+a[2]+k)*cost[1]+(a[1]+a[2]+k)*cost[2]
= + a[2]*cost[1]  - k*cost[2] >=0 
it is optimal to merge the next element in the previsous group

= a[r]*cost[r-1] > k*cost[r]

3 1 4


[3 1 4] 
(3+1+4+1)*(8) = 72
[3] [1 4]

[3 1] [4] = (3+1+1)*(5) + (3 +1 + 4+2)*3
= 25 + 30 = 55

[3] [1] [4]

(3+1)*(2) + (3+1+2)*3 + (3+1+4+3)*3
= 8+ 18+ 33= 59
(3+1)*2 + (1+4+2)*6 = 8+ 42


(a[0] .... a[i]+a[i+1]+a[i+2]+a[i+3]+a[j] + r*k)*(cost[i]+cost[i+1]..cost[j])

(a[0].....                            a[j-1] + a[j] - a[j]+ r*k)*(cost[i]......cost[j-1] + cost[j]- cost[j]) 
(a[0].. a[j]+rk)*-(cost[j]) - a[j]*()
+ (a[0]..............................a[j] + r*k + k)*(cost[j])
*/





