#include <bits/stdc++.h>
  using namespace std;
  
  void rec(int i, int sum, int arr[], vector<vector<int>> &dp){
    
    int n=dp.size();
    int k=dp[0].size()-1;
    
    if(sum>k || i>=n) return;
    
    rec(i+1, sum, arr, dp); 
    
    if(sum+arr[i] <=k) dp[i][sum+arr[i]]+=1;
    
    rec(i+1, sum+arr[i], arr, dp);
  }

  int main() {

   int n,k; cin>>n>>k;
   
   int arr[n];
   int sum=0;
   for(int i=0; i<n; i++){
     cin>>arr[i];
     sum+= arr[i];
   }
   
   if(sum<2*k){
     cout<<0<<endl; return 0;
   }
   
   vector<vector<int>> dp(n, vector<int> (k+1, 0));
   int ex=0;
   dp[0][0]=1;
   
   rec(0, 0, arr, dp);
   int bad=0;
   
   for(int i=0; i<n; i++) for(int j=0; j<k; j++) bad+=dp[i][j];  
   for(int i=0; i<n; i++) ex+=dp[i][k];  
   if(sum!=2*k) ex=0;
   
   long long ans=(1ll<<(n-1)) - bad;
   cout<<2*ans - ex<<endl;
   
 
  }