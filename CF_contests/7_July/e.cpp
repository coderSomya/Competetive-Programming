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
const int N=1e6;
 
unordered_set<int> pos;

void init(){
    for(int i=2; i<=N; i++)
    {   
        int curr=1;
        int temp=1;
        int c=0;
        while(curr<=N){
           if(c>=2) pos.insert(curr);
           temp*=i;
           curr+=temp;
           c++;
        }
    }
}
void solve(){
    int n; cin>>n;
    
    // for(int k=2; k<n; k++){
    //     int r=n*(k-1)+1;
    //     int m=0;
    //     while(r%k==0 && r>1){
    //         r/=k; m++;
    //     }

    //     if(r==1 && m>2){
    //         cout<<"YES"<<" "<<endl;
            
    //         return;
    //     }
    // }
   if(pos.count(n)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
init();
while(t--) solve();
return 0;
}