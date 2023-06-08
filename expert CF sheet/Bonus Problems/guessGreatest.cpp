/*
problem link->
https://codeforces.com/problemset/problem/1486/C1
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

int query(int l,int r){
    cout<<"?"<<" "<<l<<" "<<r<<endl;

    int res; cin>>res;
    return res;
}

void answer(int x){
    cout<<"!"<<" "<<x<<endl;
    return;
}
 
 
void solve(){
    take_n

    int l=1; int h=n;
  
    while(h-l>1){
     
     int mid=(l+h)/2;
     int x=query(l,h);
     int y;
     if(x>=mid){
        y=query(mid,h);
     }
     else y=query(l,mid);

     
     if(x>=mid){
        if(x==y){
           l=mid;
        }else{
      h=mid-1;
        }
     }
     else{
        if(x==y){
           h=mid;
        }else{
          l=mid+1;
        }
     }
      
    }
    int ans;
    if(h-l==0){
        ans=l;
    }
    else{
      int second=query(l,h);
      ans=l+h-second;
    }
    


    answer(ans);

}
  
  
int32_t main(){

 solve();
return 0;
}