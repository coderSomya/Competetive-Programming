/*
problem link->
https://codeforces.com/problemset/problem/1796/C
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
  
  
const int mod= 998244353;
const int inf= 1e15;

int pow2[21];
int pow3[15];


 
void solve(){
    int l,r; cin>>l>>r;
    int ans2=0;
    loop(i,0,21){
        if(pow2[i]*l<=r) ans2++;
        else break;
    }
    int ans3=0;
    loop(i,0,15){
        if(pow3[i]*l<=r) ans3++;
        else break;
    }

    //check for all numbers...
    int global =0;

    if(ans2==ans3){
    loop(i,l,r){
        int temp=0;
        for(int j=0; j<21; j++){
            if(pow2[j]*i<=r) temp++;
            else break;
        }
        if(temp==ans2) {
            global++; 
        }
    }
    loop(i,l,r){
        int temp=0;
        for(int j=0; j<15; j++){
            if(pow3[j]*i<=r) temp++;
            else break;
        }
        if(temp==ans2) global++;
    }
    }
    else{

        loop(i,l,r){
        int temp=0;
        for(int j=0; j<21; j++){
            if(pow2[j]*i<=r) temp++;
            else break;
        }
        if(temp==ans2) global++;
    }

    }

    cout<<ans2<<" "<<global%mod<<endl;
}
  
  
int32_t main(){
pow2[0]=1;
pow3[0]=1;
loop(i,1,21) pow2[i]=pow2[i-1]*2;
loop(i,1,15) pow3[i]=pow3[i-1]*3;
int t;
cin>>t;
while(t--) solve();
return 0;
}