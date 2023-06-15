/*
problem link->
https://codeforces.com/problemset/problem/1473/D
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

int findmax(const vector<vector<int>> &maxi, int start, int end){
   int dist=log2(end-start+1);
   cout<<dist<<endl;
   cout<<start<<" "<<start+(1<<dist)<<" "<<end-(1<<dist)<<endl;
   return max(maxi[start][dist], maxi[end-(1<<dist)][dist]);

}

int findmin(const vector<vector<int>> &mini, int start, int end){
   int dist=log2(end-start+1);

   return min(mini[start][dist], mini[end-(1<<dist)+1][dist]);
}
 
 
void solve(){
    int n,m; cin>>n>>m;
    string s; cin>>s;

    int arr[n];
    arr[0]=(s[0]=='+') ? 1 : -1;
    loop(i,1,n) {
        if(s[i]=='+') arr[i]=arr[i-1]+1;
        else arr[i]=arr[i-1]-1;
    }
   cout<<"made prefix array"<<endl;
    //build a sparse table

    vector<vector<int>> maxi(n, vector<int> (20));
    vector<vector<int>> mini(n, vector<int> (20));

    //maxii=(i,j)-> maximum in the range i... i+2^j

    loop(i,0,n) maxi[i][0]=arr[i];
    loop(i,0,n) mini[i][0]=arr[i];

    for(int pow=1; pow<20; pow++){
        for(int i=0; i<n; i++){
            if(i+(1<<pow) < n) {

          
            maxi[i][pow]=max(maxi[i][pow-1], maxi[i+(1<<(pow-1))][pow-1]);
            mini[i][pow]=min(mini[i][pow-1], mini[i+(1<<(pow-1))][pow-1]);

            }
        }
    }

    cout<<"made sparse table"<<endl;
   
   while(m--){
    int l,r;
    cin>>l>>r;
   l--; r--;
    int small=(l>0) ? findmin(mini, 0, l-1) : inf;
    int large= (l>0) ? findmax(maxi, 0, l-1) : -inf;

    int small2=(r<n-1) ? findmin(mini, r+1, n-1) : inf;
    int large2=(r<n-1) ? findmax(maxi, r+1, n-1) : -inf;

   int gap=arr[r]-((l>0) ? arr[l-1] : 0);
   cout<<"gap = "<<gap<<endl;
   small2-=gap;
   large2-=gap;
   small=min({(int) 0,small, small2});
   large=max({(int) 0,large, large2});

   cout<<large-small+1<<endl;
   }
    

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}