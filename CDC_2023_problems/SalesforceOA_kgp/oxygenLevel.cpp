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

vector<int> v;
int n,T;

// vector<int> prefAND;


bool check(int x, vector<vector<int>> &pref){

    
    for(int i=0; i<n; i++){
        int dist=n-i;
        //binary search on dist

        int l=1; int h=dist;

        while(l<=h){
            int mid=(l+h)/2;

            int fact=log2(mid);

            int val = pref[i][fact-1]&pref[i+(1<<(fact-1))-1][fact-1];
            int diff;
            if(val>T){
                diff=val-T;
                if(diff>x){
                    l=mid+1;
                }
                else return true;
            }
            else{
                diff=T-val;
                if(diff>x){
                    h=mid-1;
                }
                else{
                    return true;
                }
            }
        
        }
    }

    return false;
}
 
void solve(){
    cin>>n;
    v.clear();
    v.resize(n);

    loop(i,0,n) cin>>v[i];
    cin>>T;

    vector<vector<int>> prefAND(n,vector<int>(20));

    //prefAND(i, j) =  prefAND of i......i+2^j

    //prefAND(i,j) - prefAND(i, j-1)&prefAND(j- (1<<(j-1)) , j-1)

    for(int i=0; i<n; i++){
        prefAND[i][0]=v[i];
    }

    for(int factor=1; factor<20; factor++)
    {
        for(int j=0; j<n; j++){
            if(j + (1<<factor) >n) continue;
            
            int x= prefAND[j][factor-1];
            int y= prefAND[j + (1<<(factor-1))][factor-1];

            int z= x&y;
            // cout<<x<<" "<<y<<" "<<z<<endl;


            prefAND[j][factor]= z;
        }
    }


   

    int l=0; int h=T;

    int ans=T;

    while(l<=h){

        int mid=(l+h)/2;

        if(check(mid, prefAND)){
            ans=mid;
            h=mid-1;
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


/*
test case

4 
9 12 3 7
5


*/