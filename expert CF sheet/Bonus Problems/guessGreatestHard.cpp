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

int query(int l,int r){
    if(l==r) return -1;
    cout<<"?"<<" "<<l<<" "<<r<<endl;

    int res; cin>>res;
    return res;
}

void answer(int x){
    cout<<"!"<<" "<<x<<endl;
}

int binary_search_left(int l, int r, int smax){

}

int binary_search_right(int l, int r, int smax){
    
}
 
void solve(){
    int n; cin>>n;

    //find the smax
    int smax=query(1,n);
    //find wether max is in second half or first half

    int x=query(1,smax);
    int y=query(smax,n);
    
    if(x==smax){
        //left me hai
       int res= binary_search_left(1,smax, smax);
    }
   
    else{
    //right me hai
       
        int res=binary_search_right(smax,n, smax);
    }
    


}
  
  
int32_t main(){

solve();
return 0;
}