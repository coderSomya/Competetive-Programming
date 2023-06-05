#include <bits/stdc++.h>
using namespace std;
#define loop(i,l,r)     for(int i=l; i<r; i++)
#define int             long long
#define pb              push_back
#define vi              vector<int>
#define mkp             make_pair<int,int>
#define umpii           unordered_map<int,int>
#define maxheap         priority_queue<int>
#define minheap         priority_queue<int, vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)     __builtin_ctzll(x)
#define in_arr(A,n)     loop(i,0,n) cin>>A[i];
#define p_arr(A,n)      loop(i,0,n) cout<<A[i]
;
#define pln_arr(A,n)    loop(i,0,n) cout<<A[i]<<endl
#define take_n          int n; cin>>n;
#define take_arr        int arr[n]; loop(i,0,n) cin>>arr[i];
  
  
const int mod= 1e9+7;
const int inf= 1e15;

bool isPrime(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }

    return true;
}
 
  
void solve(){

    int n,m;
    cin>>n>>m;

    int dp[n][m];
    
    bool x=isPrime(n);
    bool y=isPrime(m);

    if(!x){
       //1
       //2
       for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dp[i][j]=j*n+(i+1);
        }
       }
    }
    else if(!y){
    //1,2,3
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dp[i][j]=i*m+(j+1);
        }
    }
    }

    else{
       if(n!=2 && m!=2){
            
         unordered_map<int,int>mp;
         mp[n/2]=0;
         

         int ct=2;
         for(int i=1; n/2-i>=0; i++){
            mp[n/2-i]=ct;
            ct++;
            mp[n/2+i]=ct;
            ct++;
         }
         mp[n-1]=1;

         for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dp[i][j]=mp[i]*m+j+1;
            }
         }

       }

       else{
        if(n==2){
          for(int i=0; i<m; i++){
           dp[0][i]=i+1;
          }
          for(int i=0; i<m-1; i++){
            dp[1][i]=m+i+2;
          }
          dp[1][m-1]=m+1;
        }
        else{

            for(int i=0; i<n;i++) dp[i][0]=i+1;
            for(int j=0; j<n; j++) dp[j][1]=n+j+2;
        }
        dp[n-1][1]=n+1;
       }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}