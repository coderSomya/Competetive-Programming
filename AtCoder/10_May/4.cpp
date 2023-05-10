#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,q;
    cin>>n>>q;

    int r=1;
    vector<int> ans;
    set<int> st;
    while(q--){
      int type; cin>>type;
     

      if(type==1){
        st.insert(r); r++;
      }
      else if(type==2)
      { 
        int x; cin>>x;
        st.erase(x);
      }
      else{
        ans.push_back(*(st.begin()));
      }
    }

    for(auto x: ans) cout<<x<<endl;
}

int main(){
    solve();

    return 0;
}