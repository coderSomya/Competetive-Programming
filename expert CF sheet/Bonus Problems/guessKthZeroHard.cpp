/*
problem link->
https://codeforces.com/contest/1520/problem/F1
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
const int N=2e5;
 
int query(int l, int r){
    cout<<"?"<<" "<<l<<" "<<r<<endl;

    int res; cin>>res;
    return res;
}

int dist(int a, int b){
    return b-a+1;
}

vector<int>BIT(N+1,0);

void update(int idx, int val){
    
    while(idx<=N){
        BIT[idx]+=val;
        idx+=idx&(-idx);
    }
}

int sum(int n){
   
   int sum=0;
   while(n>0){
    sum+=BIT[n];
    n-=n&(-n);
   }

   return sum;
}

void solve(){
    int n; int t; 
    cin>>n>>t;
    while(t--){
        int k; cin>>k;

        int l=1; int r=n;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
          
            int res=(sum(mid)- sum(l-1))+ query(l,mid);
           
            int zeroes=dist(l,mid)-res;
            if(zeroes<k){
                l=mid+1;
                k-=zeroes;
            }
            else{
                ans=mid;
                r=mid-1;
            }
        }

        cout<<"!"<<" "<<ans<<endl;
        update(ans,1);
    }
}
  
  
int32_t main(){

solve();
return 0;
}