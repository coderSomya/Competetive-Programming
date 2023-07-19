/*
https://www.desiqna.in/7299/atlassian-sde1-coding-questions-solutions-2022-oncampus-2022
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


int bs(vector<int> &arr, int val , int i, int j){



    int l=i; int h=j;

    int ans=l;

    while(l<=h){
        int mid=(l+h)/2;

        if(arr[mid]<=val){
            ans=mid;
            l=mid+1;
        }
        else h=mid-1;
    }

    return ans;
}


int check(vector<int> &arr, int pref[],  int l, int h, int val){

    // int i=l; int j=h;

    int idx= bs(arr, val, l , h);

    int sum=0;
    sum-= pref[idx] - (l ? pref[l-1] : 0)- (idx-l+1)*val;

    sum+= (pref[h]-pref[idx]) - (h-idx)*val;

    return sum;
}
 
 
void solve(){

    int n,k; cin>>n>>k;

    vector<int> v(n);
    loop(i,0,n) cin>>v[i];

    sort(v.begin(), v.end());

    int pref[n];
    pref[0]=v[0];
    loop(i,1,n) pref[i]=pref[i-1]+v[i];


    int l=0; int h=k-1; 

    int ans= inf;

    while(h<n){
        int sum=pref[h]-(l? pref[l-1] : 0);
        int a= sum/k;
        int b= a+1;

        int temp1= check(v, pref, l, h, a);
        int temp2= check(v, pref, l, h, b);

        ans= min(ans, min(temp1, temp2));

        l++; h++;
    }

    cout<<ans<<endl;



}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}