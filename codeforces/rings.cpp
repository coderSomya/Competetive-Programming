/*
problem link ->
https://codeforces.com/problemset/problem/1562/C
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
    string s; cin>>s;
    bool solved = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                solved = true;
                if (i >= n / 2) {
                    cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
                    break;
                } else {
                    cout << i + 2 << " " << n << " " << i + 1 << " " << n << endl;
                    break;
                }
            }
        }
        if (!solved) {
            cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
        }
    }

  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}