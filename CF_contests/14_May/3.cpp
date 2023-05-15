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
 
int next(int arr[], int target, int end)
{
    int start = 0;
 
    int ans = end+1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
 
        // Move to right side if target is
        // greater.
        if (arr[mid] <= target)
            start = mid + 1;
 
        // Move left side.
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }
 
    return ans;
}
 
void solve(){
    take_n
    int a[n], b[n];

    loop(i,0,n) cin>>a[i];
    loop(i,0,n) cin>>b[i];

    sort(a,a+n);
    int freq[n];
    for(int i=0;i<n;i++){
      int temp=next(a,b[i], n-1);
      freq[i]=n-temp;
    }

    sort(freq, freq+n);
    int red=0;
    int res=1;

    // for(int i=0;i<n; i++) cout<<freq[i]<<" ";
    // cout<<endl;
    for(int i=0; i<n; i++){
        if(freq[i]-red<=0){
            cout<<"0"<<endl;
            return;
        }
       res=res*(freq[i]-red)%mod;
       red++;
    }

    cout<<res<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}