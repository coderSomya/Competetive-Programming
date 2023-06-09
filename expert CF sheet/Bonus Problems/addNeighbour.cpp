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

bool check(int arr[], int n, int x){
    int curr=0;
    for(int i=0; i<n; i++){
        curr+=arr[i];
        if(curr>=x){
            curr=0;
        }
    }

    return curr==0;
}

//could instead check for all divisors :(
 
 
void solve(){
    take_n
    take_arr

    int pref[n];
    pref[0]=arr[0];
    loop(i,1,n) pref[i]=pref[i-1]+arr[i];

    unordered_map<int,int> mp;
    
    int ans=0;
    for(int i=0; i<n-1; i++){
       int x=pref[i];
       int temp=1;
       
       for(int j=1; j*j<=x; j++){
        if(x%j==0){
            //x can be written as j*(x/j)
            //if we have seen (j-1)*(x/j) and its value was j-1
            //we can make the value of x as j
            if(mp.find((j-1)*(x/j))!=mp.end() && mp[(j-1)*(x/j)]>=j-1){
                temp=max(temp, j);
            }
            if(mp.find(j*((x/j)-1))!=mp.end() && mp[j*((x/j)-1)]>=(x/j)-1){
                temp=max(temp,x/j);
            }
        }
       }

       mp[x]=temp;
       
    }

    for(int i=1; i*i<=pref[n-1]; i++){
        if(pref[n-1]%i==0){
          if(mp.find((i-1)*(pref[n-1]/i))!=mp.end() && mp[(i-1)*(pref[n-1]/i)]>=i-1){
            ans=max(ans, i);
          }

           if(mp.find((i)*(pref[n-1]/i - 1))!=mp.end() && mp[(i)*(pref[n-1]/i - 1)]>=pref[n-1]/i-1){
            ans=max(ans, pref[n-1]/i);
          }
        }
    }


    int sum=pref[n-1];
    
    int res=n-ans;

    cout<<res<<endl;

}
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}







