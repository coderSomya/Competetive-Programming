/*
problem link ->
https://codeforces.com/problemset/problem/1777/C
*/
const int N=1e5+1;
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m; cin>>n>>m;
    unordered_set<int> st;
    vector<int> v;
    vector<int> ems(m+1,0);
    int ct=0;

    for(int i=0; i<n; i++){
        int x; cin>>x;
        st.insert(x);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int maxi=-1;
    for(int i=0; i<n; i++){
       
       //v[i] ke sare factors ka count badhao, jinka pehli baar badh raha hai, ct++ karo
       //agar ct=m ho gaya that means sare no.s ke multiples milgaye hain

       for(int j=1; j*j<=v[i]; j++){
        
        if(v[i]%j==0){
           if(j<=m) {
            ems[j]++; if(ems[j]==1) ct++;
           }
           if(j*j!=v[i] && v[i]/j<=m){
            ems[v[i]/j]++; if(ems[v[i]/j]==1) ct++;
           }
        }
    
       }

       if(ct>=m){
        //mil gaya maxi
        maxi=i;
        break;
       }
    }

    if(maxi==-1){

        cout<<maxi<<endl;
        return;
    }

   //now do the reverse


   vector<int> ems2(m+1,0);
   for(int i=0; i<n; i++){
    bool flag= false;
    for(int j=1;j*j<=v[i]; j++){
        if(v[i]%j==0){
            if(j<=m){
                ems2[j]++;
                if(ems2[j]==ems[j])
                {
                    //mil gaya min
                    flag=true;
                    break;
                }
            }
            if(j*j!=v[i] && v[i]/j<=m){
                ems2[v[i]/j]++;
                if(ems2[v[i]/j]==ems[v[i]/j]){
                    flag=true;
                    break;
                }
            }
        }
    }

    if(flag){
        cout<<maxi-i<<endl;
        return;
    }
   }
    
    
    
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}