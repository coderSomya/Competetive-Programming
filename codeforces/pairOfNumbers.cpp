/*
problem link - https://codeforces.com/problemset/problem/1790/E
*/

/*
always go for simplest possible solutions as your base
*/

/*
take a=x; b=0;

a= a^b + a&b
b=a&b;

a=3x/2, b=x/2

check if everything still holds true
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

    int x; cin>>x;

    if(x%2){
        cout<<"-1"<<endl; return;
    }

    int a= 3*x/2; int b= x/2;
    int m= a^b;
    if(m == x){
       
        cout<<a<<" "<<b<<endl;
    }
    else{
     cout<<-1<<endl;
    }

}
  
  
int32_t main(){

int t;
cin>>t;
while(t--) solve();
return 0;
}