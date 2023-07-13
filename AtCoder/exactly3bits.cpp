#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n; cin>>n;

    vector<int> v(61, 0);
    int ct=0;
    for(int i=0; i<61; i++){
        if((n&((1ll<<i)))!=0) v[i]=1;
        else v[i]=0;

        ct+=v[i];
        // if(v[i]==1) cout<<i<<" ";
    }
   if(n<7) {
    cout<<"-1"<<endl;
    return;
   }


// cout<<"Yes"<<endl;
// cout<<ct<<endl;
   if(ct>=3){
    for(int i=0; i<=60; i++){
        if(ct==3) break;
          if(v[i]==1){
            v[i]=0;
            ct--;
        }
    }

    long long ans=0;
    for(int i=0; i<61; i++){
        ans+= (1ll<<i)*(v[i]);
    }


    cout<<ans<<endl;
    return;
   }



   if(ct==1){
    for(int i=0; i<61; i++){
         if(v[i]==1){
            v[i]=0; v[i-1]=1; v[i-2]=1; v[i-3]=1;
            // cout<<i<<endl;
            break;
         }
    }
    long long ans=0;
    for(int i=0; i<61; i++){
        ans+= (1ll<<i)*(v[i]);
    }


    cout<<ans<<endl;
    return;
    
   }


   if(ct==2){
      if(v[0]!=1 && v[1]!=1){


    long long ans=0;
        for(int i=2; i<61; i++){
            if(v[i]==1){
                v[i-1]=1;
                v[i-2]=1;
                // ans+= 1<<(i-3);
                v[i]=0;
                break;
            }
        }

        for(int i=0; i<61; i++){
            ans+= v[i]*(1ll<<i);
        }

        cout<<ans<<endl;
        return;
      }



      else{
          long long ans=0;
        for(int i=61; i>=0; i--){
            if(v[i]==1){
                 ans+= 1ll<<(i-1);
                 ans+=1ll<<(i-2);
                 ans+= 1ll<<(i-3);
                v[i]=0;
                cout<<ans<<endl;
                return;
            }
        }
      }
   }


}

int main(){
   int t; cin>>t;
   while(t--) solve();

   return 0;
}