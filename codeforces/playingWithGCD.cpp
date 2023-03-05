/*
problem link->
https://codeforces.com/problemset/problem/1736/B
*/

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
 
 
void solve(){

    //find prime no.s from 2..100
    vi primes;
    loop(i,2,100){
        bool flag=true;
        loop(j,2,i){
           
            if(i%j==0){
              flag=false;
              break;
            }
        }
        if(flag) primes.pb(i);
    }

    int p=primes.size();

    take_n
    take_arr

    vector<vector<int>> v(n,vector<int>(p,0));
    loop(i,0,n){
        loop(j,0,p){
            int c=0;
            while(arr[i]%primes[j]==0){
                c++;
                arr[i]/=primes[j];
            }
            v[i][j]=c;
        }
    }
   
  


    for(int i=1; i<n-1; i++){
        for(int j=0; j<p; j++){
            if(v[i][j]<v[i+1][j] && v[i][j]<v[i-1][j]){
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    cout<<"YES"<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}