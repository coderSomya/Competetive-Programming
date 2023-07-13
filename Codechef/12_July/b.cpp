#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int main() {
	// your code goes here
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	     
	     set<int> st;
	     
	     int a[n], b[n];
	    int ans=1;
	    for(int i=0; i<n; i++){
	       cin>>a[i];
	    }
	    
	    for(int i=0; i<n; i++) cin>>b[i];
	    
	    st.insert(a[0]); st.insert(b[0]);
        int ct=0;
	    
	   // int ans= 2*n - (int)(st.size());
       set<pair<int,int>> ast;
       ast.insert({a[0], b[0]});

       vector<int> v(1440, 1);
       v[a[0]]--; v[b[0]]--;
	   
	   for(int i=1; i<n; i++){
      
         if(v[a[i]]+ct== 0|| v[b[i]]+ct==0){
            //new airline;
            ans++;
            //range update
            ct++;
         }
         v[a[i]]--; v[b[i]]--;

	   }
	   
	    
	    cout<<ans<<endl;
	}
	return 0;
}
