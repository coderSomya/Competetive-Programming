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
    vector<vector<char>> grid(3, vector<char> (3));

    map<char,int> mp;
    mp['X']=1;
    mp['O']=2;
    mp['.']=3;
    mp['+']=4;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            char ch; cin>>ch;
            grid[i][j]=ch;
        }
    }


    for(int i=0; i<3; i++){
        if(grid[i][0]==grid[i][1] && grid[i][0]==grid[i][2]){
              if(grid[i][0]!='.'){
                cout<<grid[i][0]<<endl;
                return;
              }
        }
    }

     for(int i=0; i<3; i++){
        if(grid[0][i]==grid[1][i] && grid[2][i]==grid[0][i]){
              if(grid[1][i]!='.'){
                cout<<grid[1][i]<<endl;
                return;
              }
        }
    }

    if(grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2]){
        if(grid[0][0]!='.'){
            cout<<grid[0][0]<<endl;
            return;
        }
    }

    if(grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0]){
        if(grid[0][2]!='.'){
            cout<<grid[1][1]<<endl; return;
        }
    }

    cout<<"DRAW"<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}