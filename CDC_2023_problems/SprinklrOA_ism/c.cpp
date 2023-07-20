#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n,m;cin>>n>>m;

    vector<int> v(n);

    for(int i=0; i<n; i++) cin>>v[i];

    unordered_map<int,int> freq;
    set<int> z;
      set<int> st;
    for(int i=0; i<n;i++){
        freq[v[i]]++;
        st.insert(v[i]);
    }
    
    int curr=0;
    while(m){
        
        int ff= *st.begin();
        int real= *(st.begin());
        st.erase(ff);
        ff-=curr;
       

        if(n*ff<=m){
            //utna round trips

            n-= freq[real];
            z.insert(real);
            m-=ff;
            curr+=ff;
        }

        else{

          curr+=m/n;
          m=m%n;
          for(int i=0; i<n; i++){
            if(m==0) break;
            if(z.count(v[i])!=0){
                m--;
                v[i]--;
            }
          }
        }
    }

    for(int i=0; i<n; i++){
        if(z.count(v[i])!=0){
            v[i]=0;
        } 
        else v[i]-=curr;
    }

    for(int i=0; i<n; i++) cout<<v[i]<<" ";
    cout<<endl;
     

}

int main()
{
    int t; cin>>t;
    while(t--) solve();

    return 0;
}
