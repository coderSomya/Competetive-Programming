/*
problem link -
https://codeforces.com/contest/1789/problem/B
*/

/*
not the greatest implementation, but good enough
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

bool func(string s, int l, int r){
    string s1; int n=s.length();
    for(int i=0; i<n; i++){
        if(s[i]=='0') s1+='1';
        else s1+='0';
    }

    while(l<=r){
        if(s1[l]!=s[r]){
            // int x=l;
            break;
        }
        l++; r--;
    }

    if(l>r){
        return true;
    }
    else{
        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            l++; r--;
        }

        if(l>r) {
            return true;
        }
    }
}

bool func2(string s, int l, int r){
     string s1; int n=s.length();
    for(int i=0; i<n; i++){
        if(s[i]=='0') s1+='1';
        else s1+='0';
    }

    while(l<=r){
        if(s[l]!=s1[r]){
            // int x=l;
            break;
        }
        l++; r--;
    }

    if(l>r){
        return true;
    }
    else{
        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            l++; r--;
        }

        if(l>r) {
            return true;
        }
    }
    
}
 
 
void solve(){
    int n; cin>>n;
    string s; cin>>s;
    int start=-1; int end=-1;
    //find the first differing character
    int l=0; int r=n-1;
    while(l<=r){
        if(s[l]!=s[r]){
         start=l; end=r;
         break;
        }
        l++; r--;
    }

    if(start==-1 && end==-1) {
        cout<<"YES"<<endl; return;
    }

    //check from start till end
   if(func(s,l,r)){
    cout<<"YES"<<endl;
    return;
   }

    //check from end
    else if(func2(s,l,r)){
   cout<<"YES"<<endl;
    return;
    }

    else{
        cout<<"NO"<<endl;
    }


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}