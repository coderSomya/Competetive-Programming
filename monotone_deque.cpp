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

struct monotone_deque{

  deque<int> dq;
  
  void insert(int x){
    while(!dq.empty() && dq.back()>x) dq.pop_back();

    dq.push_back(x);
  }

  void remove(int x){
      
      if(!dq.empty()){
        if(dq.front() ==x) dq.pop_front();
      }
  }

  int getMin(){
     if(!dq.empty()) return dq.front();
     return -1;
  }
};
 
 
void solve(){
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}