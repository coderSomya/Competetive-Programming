//will continue with this one


//not correct

//correct solution is a binary search approach

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
#define all(x)           x.begin(), x.end()  
  
const int mod= 1e9+7;
const int inf= 1e15;
 
 
void solve(){
    int n,k; cin>>n>>k;

    vector<int>arr(n);
    unordered_map<int,int>freq;
    unordered_map<int,int>freq2;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    vi helper(arr);
    int sum=0;
    sort(all(helper));
    for(int i=0;i<k; i++){
      freq[helper[i]]++;
      freq2[helper[i]]++;
      sum+=helper[i];
    }
    int curr=0;
    int ans=0;

    //check from the left
    for(int i=0;i<n; i++){
        if(freq.find(arr[i])!=freq.end()){
            curr+=arr[i];
            freq[arr[i]]--;
            if(freq[arr[i]]==0) freq.erase(arr[i]);
        }

        if(2*curr>=sum){
            ans=curr;
            break;
        }
    }


    //check from the right
    curr=0;
    int ans2=0;
     for(int i=n-1;i>=0; i--){
        if(freq2.find(arr[i])!=freq2.end()){
            curr+=arr[i];
            freq2[arr[i]]--;
            if(freq2[arr[i]]==0) freq2.erase(arr[i]);
        }

        if(2*curr>=sum){
            ans2=curr;
            break;
        }
    }

    cout<<min(ans, ans2)<<endl;
} 
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}