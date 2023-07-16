#include <bits/stdc++.h>
using namespace std;


void update(vector<int> &BIT, int idx, int val, int n){
   
   while(idx<=n){
      BIT[idx]+=val;
      idx+= idx&(-idx);
   }
}

int query(vector<int> &BIT, int idx, int n){
    int sum=0; 
    while(idx>0){
        // cout<<idx<<" ";
        sum+= BIT[idx];
        idx-= idx&(-idx);
    }

    return sum;
}

void solve()
{
    int n; cin>>n;
    vector<pair<int,int>> v(n);
       unordered_map<int,int> val;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        v[i]={x, i};
        val[i]=x;
    }


    sort(v.begin(), v.end());



   unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        mp[v[i].second]=i;
    }
   
    int pref[n];
pref[0]=v[0].first;
    for(int i=1; i<n; i++) pref[i]=pref[i-1]+v[i].first;

    int q; cin>>q;

    vector<int> BIT(n+1, 0);
    for(int i=0; i<n; i++){
        update(BIT, i+1, v[i].first, n);
    }


    vector<int> prev;
    
    while(q--){
        int c,k; cin>>c>>k;

        vector<int> curr(k);

        for(int i=0; i<k; i++){
            int x; cin>>x; x--; curr[i]=x;
        } 
        
           for(auto x: prev){
            int pos= mp[x];
            int value = val[x];

            update(BIT, pos, value, n);
        }
        for(auto x: curr){
            int pos= mp[x];
            int value = val[x];

            update(BIT, pos, 0, n);
        }

      

        prev=curr;

        

        int l=0; int h=n-1;
        int ans=0;
        while(l<=h)
        {
            int mid=(l+h)/2;
            
            int sum =query(BIT, mid+1, n);
            // cout<<query(BIT,n, n)<<" ";
            
            if(sum<=c){
                ans=mid+1;
                l=mid+1;
            }
           
            else h=mid-1;
        }

        cout<<ans<<endl;
    }

}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}

/*
test case
1
10
7 3 6 8 2 1 4 9 5 10
4
10 2 2 5
15 1 1
20 3 1 2 3
100 0


*/