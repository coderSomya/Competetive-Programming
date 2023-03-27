/*
problem link ->
https://codeforces.com/problemset/problem/1714/E
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
    take_n
    take_arr

    loop(i,0,n){
        arr[i]+=(arr[i]%2)*(arr[i]/10);
    }

    loop(i,0,n-1){
        if(arr[i]%10==0) continue;
        arr[i]+=20*((arr[n-1]-arr[i])/20);
    }
    
    int a[5][n];
    
    loop(i,0,n){
        a[0][i]=arr[i];
    }
    loop(i,0,n){
        loop(j,1,5){
            a[j][i]=a[j-1][i]+a[j-1][i]%10;
        }
    }

    // loop(i,0,n){
    //     loop(j,0,4){
    //         cout<<a[j][i]<<" ";
    //     }
    //     cout<<endl;
    // }


    loop(i,0,5){
        int y=a[i][n-1];
        bool f1=true;
        loop(j,0,n-1){
            bool f2=false;
            loop(k,0,5){
                if(a[k][j]==y) f2=true;
            }
            if(!f2){
                f1=false;
              break;
            }
        }
        if(f1){
            // cout<<"->";
            cout<<"YES"<<endl;
            return;
        }
    }
    // cout<<"->";
    cout<<"NO"<<endl;

   
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}