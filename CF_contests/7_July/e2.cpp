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
 


int n;


int binexpo(int a, int b){
    if(b==0) return 1;

    if(b==1) return a;

    int res=binexpo(a,b/2);;
    res*=res;

    if(b%2) res*=a;

    return res;
}

 int check(int a, int b){
   if(log2(n*(a-1)+1) > b*log2(n)) return n+1;

   int p=binexpo(a,b);
   return (p-1)/(a-1);
 }
 
void solve(){

    cin>>n;
    bool ans=false;

  
    for(int i=3; i<=60; i++){


        int l1=2; int h1=n;

        while(l1<=h1){
            int mid1=(l1+h1)/2;
             

            if(check(mid1,i)==n){
                ans=true;
                break;
            }

            else if(check(mid1,i)>n){
                h1=mid1-1;
            }

            else{
                l1=mid1+1;
            }
        }

        if(ans){
            cout<<"YES"<<endl;
            return;
        }


    }

    cout<<"NO"<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}