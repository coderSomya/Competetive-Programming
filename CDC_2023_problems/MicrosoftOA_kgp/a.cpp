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

bool check(int len, int left[], int right[], int qs[], int n){

    if(len==0) return false;

    if(len%2) return false;

    int i=0 ; int j=len-1;

    bool ans=false;

    while(j<n){
        int lside= right[i+len/2-1]-(i>0 ? right[i-1] : 0);
        int rside = left[j]- left[i+len/2];
        if(lside==0 && rside==0){
            ans=true;
        }
        i++; j++;
    }

    return ans;
}

int solution(string &S) {
    // Implement your solution here

    string s=S;

    int n=s.length();

    int left[n]={0};
    int right[n]={0};
    int qs[n]={0};

    left[0]=(s[0]=='<');
    right[0]=(s[0]=='>');

    qs[0]=(s[0]=='?');

    for(int i=1; i<n; i++)
    {
 left[i]=left[i-1]+(s[i]=='<');
 right[i]=right[i-1]+(s[i]=='>');
 qs[i]=qs[i-1]+(s[i]=='?');
    }

    int ans=0;

    int l=0; int r=n-1;
    while(l<=r){
        int mid=(l+r)/2;

        if(check(mid, left, right, qs, n)){
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }

    return ans;
}

 
 
void solve(){
  string a= "<><00>>";
  string b= "000000";
  string c= "<<0";

  cout<<solution(a)<<endl;
  cout<<solution(b)<<endl;

  cout<<"here"<<endl;
  cout<<solution(c)<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}