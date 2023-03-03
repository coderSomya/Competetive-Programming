/*
problem link -
https://codeforces.com/problemset/problem/1760/F
*/

/*
trynna do it mathematically
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

    int n,c,d;
    cin>>n>>c>>d;

    take_arr
    sort(arr, arr+n, greater<int>());

    int pref[n+1];
    pref[0]=0;
    loop(i,1,n+1) pref[i]=pref[i-1]+arr[i-1];

    if(arr[0]*d < c){
        cout<<"Impossible"<<endl;
        return;
    }

    if(pref[min(d,n)] >=c){
        cout<<"Infinity"<<endl;
        return;
    }
   
   //binary search on k

   int l=0; int r=d+2;
   int o=0;
   int ans=-1;
   while(l<r){
    // cout<<l<<" "<<r<<endl;
    //  cout<<"here for "<<o++<<"th time"<<endl;
       
      
      int k=(l+r)/2;

      //k=mid
      //x*pref[min(k+1,n)]+r=c
      //x*(k+1) + p= d
     
     int temp=0;
     for (int i = 0; i < d; i++) {
			if (i % k < n) {temp += arr[i % k];}
		}
     
     if (temp >= c) {
			l = k;
		}
		else {
			r = k- 1;
		}
   }

   cout<<l-1<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}