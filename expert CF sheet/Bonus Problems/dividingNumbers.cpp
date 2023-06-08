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

unordered_set<int> primes;
 
void solve(){
    int a,b,k;
    cin>>a>>b>>k;

    int powers=0;

    int m;
    if(a==b){
        m=0;
    }
    else if(__gcd(a,b)==a || __gcd(a,b)==b)
    {
        m=1;
    }
    else m=2;

    int n1=a, n2=b;

    for(int i=2; i*i*i<=n1; i++){
        while(n1%i==0){
            n1/=i;
            powers++;
        }
    }
    if(n1!=1) powers++;

    for(int i=2; i*i<=n2; i++){
        while(n2%i==0){
            n2/=i;
            powers++;
        }
    }
    if(n2!=1) powers++;

    if(k==1){
        if(m==1){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }

    else{
        if(k<=powers){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}
  
  
int32_t main(){

for(int i)
int t;
cin>>t;
while(t--) solve();
return 0;
}