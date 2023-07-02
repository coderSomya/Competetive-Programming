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

umpii freq;


void buildST(vector<int> &ST, vector<int> &v, int ss, int se, int idx, int stidx)
{
    if(ss>se) return;

    if(ss==se){
        ST[stidx]=v[idx];
        return;
    }

    int mid=(ss+se)/2;

     if(mid>=idx) buildST(ST, v, ss, mid, idx, 2*stidx);
     else buildST(ST, v, mid+1,se, idx, 2*stidx+1);

    ST[stidx]=ST[2*stidx]+ST[2*stidx+1];
} 

void update(vector<int> &ST, vector<int> &v, int ss, int se, int idx, int stidx, int val){
   if(ss>se) return;

    if(ss==se){
        
        
        return;
    }

    int mid=(ss+se)/2;

    update(ST, v, ss, mid, idx, 2*stidx, val);
    update(ST, v, mid+1,se, idx, 2*stidx+1, val);

    ST[stidx]=ST[2*stidx]+ST[2*stidx+1];
}

int query(vector<int> &ST, vector<int> &v, int ss, int se, int ql , int qr,  int stidx){

    if(ss>qr || se<ql){
        return 0;
    }

    if(ss>=ql && se<=qr){
        return ST[stidx];
    }
     int mid=(ss+se)/2;
    int left=query(ST, v, ss, mid, ql, qr, 2*stidx);
    int right=query(ST, v, mid+1, se, ql, qr, 2*stidx+1);

    return left+right;
}

void solve(){
    int n,q; cin>>n>>q;

    vector<int> arr(n);
    loop(i,0,n) cin>>arr[i];
   freq.clear();
    loop(i,0,n){
        freq[arr[i]]++;
    }

    vector<int> ST(4*n+1, 0);


    vector<vector<int>>dis(1001, vector<int> (n,0));

    for(int i=1; i<=1000; i++){
        dis[i][0]=(arr[0]==i);
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<=1000; j++){
            dis[j][i]=dis[j][i-1]+(arr[i]==j);
        }
}


vector<vector<int>>segtree(1001,vector<int>(4*n+1));

for(int dist=1; dist<1001; dist++)
    for(int i=0; i<n; i++){
        buildST(segtree[dist], dis[dist], 0,n-1 ,i,1);
    }




    while(q--){
        int x; cin>>x;
        if(x==1){
            int y,val;
            cin>>y>>val;
            y--;
            update(ST,arr,0,n-1,y, 1,val);
        }
        else{
            int l,r; cin>>l>>r;
            l--; r--;
            int ans=query(ST,arr,0,n-1,l,r,1);

            cout<<ans<<endl;
        }
    }

    
}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}