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

vector<int> BIT;

void update(int i, int val, int n){
   i++;
   while(i<=n){
    BIT[i]+=val;
    i+= i&(-i);
   }

}

int sum(int i){
    i++;
    int sum=0; 
    while(i>0){
        sum+=BIT[i];
        i-= i&(-i);
    }

    return sum;
} 


bool check(int x, int qs[], int n, vector<pair<int,int>> &segments){
  //check if its possible with the first x queries to have a ...
   bool ans=false;
   for(int i=0; i<x; i++){
   update(qs[i], 1, n);
   }
//   for(auto x: BIT) cout<<x<<" ";
//   cout<<endl;
   for(auto seg : segments){
    int ones=sum(seg.second)-sum(seg.first-1);
   int zeroes=seg.second-seg.first+1-ones;
    
    if(ones>zeroes){
    ans=true;
    }
   }

   for(int i=0; i<x; i++){
   update(qs[i], -1, n);
   }
   
   
   return ans;
}
 
void solve(){

    int n,m; cin>>n>>m;
    int arr[n]={0};

    vector<pair<int,int>> r;
    loop(i,0,m){
        int x,y; cin>>x>>y;
        x--; y--;
        r.push_back({x,y});
    }

    int q; cin>>q;

    int qs[q];
    for(int i=0; i<q; i++){
        cin>>qs[i];
        qs[i]--;
    }

   
    BIT.clear();
    BIT.resize(n+1,0);
    int ans=-1; 
    int l=0; int h=q;

    while(l<=h){
        int mid=(l+h)/2;

        if(check(mid, qs, n, r)){
            h=mid-1;
            ans=mid;
        }

        else l=mid+1;
    }

    cout<<ans<<endl;




}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}