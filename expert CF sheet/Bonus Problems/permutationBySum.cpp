/*
problem link->
https://codeforces.com/problemset/problem/1512/E
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
const int N= 500;
const int SUM=N*(N+1)/2;

int sum(int l, int r){
    int x= l*(l+1)/2;
    int y= r*(r+1)/2;

    return y-x;
}
 
void solve(){
   int n,l,r,s;
   cin>>n>>l>>r>>s;

   int ans[n+1]={0};
   int len=r-l+1;

   int mini=len*(len+1)/2;
   int maxi=n*len-len*(len-1)/2;

   if(s>maxi|| s<mini){
    cout<<-1<<endl;
    return;
   }

   int curr=mini;
   int rt=len;
   int last=n;
   int idx=rt;
   while(curr!=s){
    
     rt--;
     while(idx<=last) {
        idx++; curr++;
        if(curr==s) break;
     }
     if(idx>last) {
        curr--;
        last--; idx=rt; }
   }

   //1..r + idx +  last..n

 
  
int j=l;
  set<int> st;
  for(int i=1; i<=n; i++) st.insert(i);
  for(int i=1; i<=rt; i++){
     st.erase(i);
     ans[j]=i; j++;
  }

  for(int i=n; i>last; i--){
     ans[j]=i; j++;
     st.erase(i);
  }

  ans[r]=idx; st.erase(idx);


  for(int i=1; i<=n; i++){
    if(ans[i]==0){
        ans[i]=*(st.begin());
        st.erase(ans[i]);
    }
  }

  for(int i=1; i<=n; i++) cout<<ans[i]<<" ";

  cout<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}