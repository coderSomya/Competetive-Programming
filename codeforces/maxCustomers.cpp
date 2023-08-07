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

unordered_map<int,int> mp;
const int N = 2e5;
int n,m,k,p;

int cust_msk[N];
int shop_msk[N];

void rec(int i, int mask, int taken){

    if(taken==2 || i==m) return;

    mp[mask]++;

    rec(i+1, mask, taken);
    rec(i+1, mask|shop_msk[i], taken+1);
}

int check(int x){
    int res=0;
    for(int i=0; i<n; i++){
        bool flag=true;
        for(int bit=0; bit<7; bit++){
            if(x&&(1<<bit)==0 && cust_msk[i]&(1<<bit)!=0){
                flag=false; break;
            }
        }

        res+=flag;
    }

    return res;
}
 
 
void solve(){

    cin>>n>>m>>k>>p;

    for(int i=0; i<n; i++){
           int temp=0;
           for(int j=0; j<p; j++){
            int x; cin>>x;
              temp=temp|x;
           }
           cust_msk[i]=temp;
    }

    for(int i=0; i<m; i++){
        int temp=0;
        for(int j=0; j<k; j++){
            int x; cin>>x;
            temp|=x;
        }
        shop_msk[i]=temp;
    }

    rec(0,0,0);

    int maxi=0;

    for(auto x: mp){
        int ct=check(x.first);
        maxi=max(maxi, ct);
    }

    cout<<maxi<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}