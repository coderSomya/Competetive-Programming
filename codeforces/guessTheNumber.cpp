/*
problem link->
https://codeforces.com/problemset/gymProblem/101021/1
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
 string s;
int query(int i){
    cout<<i<<endl;
    cin>>s;
    if(s=="<"){
        return 1;
    }
    else{
        return 2;
    }
} 
 
void solve(){
    int l=1; int h=1000000;
    int ans; int y=0;
    while(y<=25 && l<=h){
  
        int mid=(l+h)/2;
  
        int x= query(mid);
        y++;
        if(x==1){
            
          h=mid-1;
        }
        else{
         
         l=mid+1;
        }
    }

    cout<<"! "<<ans<<endl;
}
  
  
int32_t main(){
solve();
return 0;
}