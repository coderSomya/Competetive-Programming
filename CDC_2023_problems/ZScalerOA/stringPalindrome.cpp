/*
problem link->
https://www.desiqna.in/13627/zscaler-oa-sde1-may-2023-hashing-greedy
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
    int n; cin>>n;

    vector<string> v(n);
    loop(i,0,n){
        string s; cin>>s;
        v[i]=s;
    }

    multiset<int> st;
  
    int freq[26]={0};

    for(int i=0; i<n; i++){
        string s= v[i];
        int l= s.length();

        st.insert(l/2);

        for(int j=0; j<l; j++){
            freq[s[j]-'a']++;
        }
    }

    for(int i=0; i<26; i++){
        freq[i]=freq[i]/2;
    }
    
    int ans=0;
    int curr=0;
    int rem=-1;int idx=-1;

    for(int i=0; i<26; i++){
       curr+=freq[i];

       while(!st.empty()  && curr>=(*st.begin())){
        curr-=(*st.begin());
        st.erase(st.find(*st.begin()));

        ans++;
        if(st.empty()) break;
       }
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}

/*

test case

1
4
pass sas asps df

*/

/*

2 1 2 1
1 1 2 2
1 3 1 

*/