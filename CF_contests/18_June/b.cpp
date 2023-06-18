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

int dp[101][2][2];
int find(vector<int> &v1, vector<int>&v2, int n, int i, int t1, int t2){

  if(i==n) return 0;
  int u1=(t1==1) ? v2[i] : 9;
  int u2= (t2==1) ? v2[i]: 9;
  int l1= (t1==1) ? v1[i]: 0;
  int l2= (t2==1) ? v1[i] : 0;

  
   if(dp[i][t1][t2]!=-1) return dp[i][t1][t2];
  int temp=0;
  for(int a=l1; a<=u1; a++){
    for(int b=l2; b<=u2; b++){
        int t_t1= (t1&& a==l1);
        int t_t2= (t2 && b==u2);

        temp=max(temp, abs(a-b) + find(v1,v2, n, i+1, t_t1, t_t2));
    }
  }

  return dp[i][t1][t2] = temp;
}
 
 
void solve(){
    string l,r;
    cin>>l>>r;

    int n=max(l.length(), r.length());
    memset(dp, -1, sizeof(dp));
    vector<int> v1(n,0);
    vector<int> v2(n,0);
    int x=n-1;
    while(r.length()>0){
        int rem=r.back()-'0';
        v2[x]=rem;
        r.pop_back();
        x--;
    }

 
   int y=n-1;
    while(l.length()>0){
        int rem=l.back()-'0';
        v1[y]=rem;
        l.pop_back();
        y--;
    }

    int ans= find(v1,v2, n,0,1,1);
    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}