#include <bits/stdc++.h>
using namespace std;

#define debug(...) cout<<"[ "<<#__VA_ARGS__ <<":"<<__VA_ARGS__<<" ]"<<endl;

void solve()
{
    int n; cin>>n;
    vector<int> v(n+1);

    for(int i=1; i<=n; i++){
       cin>>v[i];
    }

    if(n==2){
        if(v[1]==2){
            cout<<"No"<<endl;
            return;
        }
    }

    if(n==3){
        if(v[1]==3 && v[2]==2 && v[3]==1){
            cout<<"No"<<endl;
            return;
        }

         if(v[1]==2 && v[2]==1 && v[3]==3){
            cout<<"No"<<endl;
            return;
        }

         if(v[1]==1 && v[2]==3 && v[3]==2){
            cout<<"No"<<endl;
            return;
        }
    }

    int start=1;
    vector<pair<int,int>> ans;

    for(int i=1; i<n; i++){
        // for(auto x: v) cout<<x<<" ";
        // cout<<endl;        
        int j=start;
        int idx=-1;
        for(; j<=n-1; j++){
           if(v[j]==i){
            idx=j; break;
           }
        }

       
       if(idx==-1){
        ans.push_back({n-1, start-1});
        

        vector<int> res(n+1);
        for(int r=1; r<start; r++){
            res[r]=v[r];
        }

        res[start]=v[n-1];
        res[start+1]=v[n];

        int x=start;
        int y=start+2;

        while(x<=n){
            if(x==n-1){
                x+=2; continue;
            }

            res[y]=v[x];
            x++;
            y++;
        }
       v=res;
       i--;

       continue;

       }
        ans.push_back({idx, start-1});

        vector<int> res(n+1);
        for(int r=1; r<start; r++){
            res[r]=v[r];
        }

        res[start]=v[idx];
        res[start+1]=v[idx+1];

        int x=start;
        int y=start+2;

        while(x<=n){
            if(x==idx){
                x+=2; continue;
            }

            res[y]=v[x];
            x++;
            y++;
        }

        v=res;
        start++;

    }

    cout<<"Yes"<<endl;
    cout<<(int)ans.size()<<endl;
    for(auto x: ans) cout<<x.first<<" "<<x.second<<endl;




}

int main()
{
    solve();
    return 0;
}
