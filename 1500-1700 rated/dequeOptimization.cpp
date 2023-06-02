/*
problem link->
https://codeforces.com/problemset/problem/1579/E2
*/

#include <bits/stdc++.h>
using namespace std;


void insert(int bit[], int x, int n){
    
    while(x<=n){
        bit[x]++;
        x+=x&(-x);
    }
}

int sum(int bit[], int x){
    int sum=0;
    while(x>0){
        sum+=bit[x];
        x-=x&(-x);
    }

    return sum;
}
void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    //coordiante compression
    vector<int> helper(arr);
    sort(helper.begin(), helper.end());
    int ct=1;
    unordered_map<int, int> mp;
    mp[helper[0]]=ct;
    ct++;
    for(int i=1; i<n; i++){
        if(helper[i]==helper[i-1]) continue;

        mp[helper[i]]=ct;
        ct++;
    }

    for(int i=0; i<n; i++){
        arr[i]=mp[arr[i]];
    }

    //every element is now from 1-n

    //if we have x, we want no. of elements from 1...x-1 in the array
    int bit[n+1]={0};
    int freq[n+1]={0};

    long long ans=0;

    for(int i=0; i<n; i++){
        insert(bit, arr[i], n);
        freq[arr[i]]++;
        int less=sum(bit, max(0,arr[i]-1));
        int eq=freq[arr[i]];
        int more=sum(bit,n)-sum(bit, arr[i]);
        ans+=min(less,more);
    }

    cout<<ans<<endl;
    
    
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}