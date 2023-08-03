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

vector<int> S(61);
vector<int> K(61);

int rec(int i, int t_1, int t_2){
//bit, equality of numbers, size of number so far
    if(i<0) return (t_1!=1);

    if(!t_1 && !t_2){
         int x= rec(i-1, t_1, t_2);
         return 2*x;
    }

    else if(t_1 && !t_2){
      //we are tight on equality

      if(K[i]==1){
          return rec(i-1, 0, t_2);
      }
      else{
        return rec(i-1, 1, 0)+rec(i-1,0,0);
      }
    }

    else if(!t_1 && t_2){
        //we are tight on ub

        if(S[i]==0){
           if(K[i]==0){
             return rec(i-1,t_1, t_2);
           }
           else{
             return rec(i-1, 0,1);
           }
        }
        else{
            //i can put 1 as well as 0
           if(K[i]==0){
               //can i put zero
               //yes
               return rec(i-1, 0,0) + rec(i-1,0,1);
           }
           else{
              //put 0 + put 1
              return rec(i-1, 0,0)+ rec(i-1, 0,1);
           }
        }
    }

    else{

        //tight on both things

        if(S[i]==0){
          if(K[i]==0){
              return rec(i-1, t_1, t_2);
          }
          else{
             return rec(i-1, 0,1);
          }
        }
        else{
            if(K[i]==0){
                return rec(i-1,1,0)+rec(i-1, 0,1);
            }
            else{
               return rec(i-1, 0, 0);
            }

        }

    }

}
 
 
void solve(){

    int n,k; cin>>n>>k;

    for(int i=60; i>=0; i--){
      if((n&(1ll<<i))!=0){
        S[i]=1;
      }
      else S[i]=0;
    }

    for(int i=60; i>=0; i--){
      if((k&(1ll<<i))!=0){
        K[i]=1;
      }
      else K[i]=0;
    }

    // for(auto x: S) cout<<x<<" ";
    // cout<<endl;
    // for(auto x: K) cout<<x<<" ";
    // cout<<endl;


    int ans=rec(60, 1,1);
    cout<<ans-(k!=0)<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}