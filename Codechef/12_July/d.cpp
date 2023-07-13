#include <bits/stdc++.h>
using namespace std;

void solve(){


    int n; cin>>n;
    vector<vector<int>> v(26);

    string s; cin>>s;

    for(int i=0; i<n; i++){
        v[s[i]-'a'].push_back(i+1);
    }

    if(n%3==1){
        cout<<"Yes"<<endl; return;
    }



if(n%3==0){

 vector<int> st(26,0); vector<int>en(26,0);
 for(int i=0; i<n; i+=3){
    st[s[i]-'a']++;
    en[s[i+2]-'a']++;

    if(st[s[i+2]-'a']!=0){
        cout<<"yes"<<endl;
        return;
    }
 }


}



else{

//i..... i+3x+1
 vector<int> st(26,0); vector<int>en(26,0);
 for(int i=0; i<n; i+=3){
    st[s[i]-'a']++;
    // en[s[i+2]-'a']++;

    if(st[s[i+1]-'a']!=0){
        cout<<"yes"<<endl;
        return;
    }
 }



}
     
cout<<"No"<<endl;
        

}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}