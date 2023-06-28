#include <bits/stdc++.h>
using namespace std;

vector<int> v;


void populate(int x, int y, int z){

  int a1=(x-y+z)/2;
  int a2=(x-a1);
  int a3=(z-a1);

  v.push_back(a1);
  v.push_back(a2);
  v.push_back(a3);
}

int query(int a, int b, string type){

    string q=type;
    q+=" ";
    q+=a+'0';
    q+=" ";
    q+=b+'0';

    cout<<q<<endl;
    int res; cin>>res;
    return res;
}

void solve(){
    int n,k; cin>>n>>k;
    v.clear();
   int i=1;
    for(; i+2<=n; i+=3){
        
        int a1pa2=query(i,i+1 ,"or")+ query(i,i+1, "and");
        int a2pa3=query(i+1,i+2 ,"or")+ query(i+1,i+2, "and");
        int a3pa1=query(i,i+2 ,"or")+ query(i,i+2, "and");

        populate(a1pa2, a2pa3, a3pa1);

    }

    int rem=n%3;

    for(; i<=n; i++){
         int m= query(1,i,"or")+query(1,i,"and") - v[0];
         v.push_back(m);        
    }

    sort(v.begin(), v.end());

    cout<<"finish "<<v[k-1]<<endl;
  
}

int main(){
    // int t; cin>>t;
    // while(t--) 
    solve();

    return 0;
}
