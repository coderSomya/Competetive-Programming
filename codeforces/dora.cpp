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
 
 
void solve()
{
    take_n
        take_arr
            vi peaks;
    peaks.pb(1);
    loop(i, 1, n - 1)
    {
        if ((arr[i] - arr[i - 1]) * (arr[i] - arr[i + 1]) > 0)
            peaks.pb(i + 1);
    }

    if (n != 1)
        peaks.pb(n);

    if (peaks.size() <= 3)
    {
        cout << -1 << endl;
        return;
    }

    vi v;
    loop(i, 0, n) v.pb(arr[i]);

    sort(v.begin(), v.end());

    deque<int> q;
    loop(i, 0, n)
    {
        q.push_back(v[i]);
    }

    int l = 0;
    int r = n - 1;

        while (l <= r) {
        if (arr[l] == q.front()) {
            l++;
            q.pop_front();
        } else if (arr[l] == q.back()) {
            l++;
            q.pop_back();
        } else if (arr[r] == q.front()) {
            r--;
            q.pop_front();
        } else if (arr[r] == q.back()) {
            r--;
           q.pop_back();
        } else {
            break;
        }
    }
    if(l <= r){
        cout << l + 1 << " " << r + 1 << endl;
    } else{
        cout << -1 << endl;
    }
}

  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}