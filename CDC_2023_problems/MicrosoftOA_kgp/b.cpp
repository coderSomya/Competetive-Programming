// you can use includes, for example:
#include <bits/stdc++.h>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int ans=0;
vector<int> len;

void dfs(int src, int par, vector<vector<int>> &adj){
    
    if(len[src]!=-1) return;
    for(auto x: adj[src]){
        if(x!=par)
        dfs(x, src, adj);
    }

    int temp=0;

    for(auto x: adj[src]){
        temp=max(temp, len[x]);
    }

    len[src]=1+temp;
    
 }


string solution(vector<string> &A) {
    // Implement your solution here
// cout<<"here"<<endl;
    int n= A.size();
    len.clear(); len.resize(n,-1);
    
    vector<vector<int>> adj(n);

    vector<vector<int>> st(26);

    for(int i=0; i<n; i++){
        // cout<<A[i][0]-'a'<<endl;
        st[A[i][0]-'a'].push_back(i);

    }

    // cout<<"here"<<endl;

    for(int i=0; i<n; i++){
        string s=A[i];
 int m= A[i][s.length()-1]-'a';
 
        for(auto y: st[m]){
            if(i!=y)
            adj[i].push_back(y);
        }
    }




vector<int> vis(26, 0);

// cout<<"here"<<endl;
for(int i=0; i<n; i++){
    if(!vis[i]){
        dfs(i, -1, adj);
    }
}
int maxi=0;
for(int i=0; i<n; i++) {
    maxi=max(maxi, len[i]);
}

string ans="";

// for(int i=0; i<maxi; i++){
//   ans+='1';
// }

// for(int i=maxi; i<n; i++){
//     ans+='0';
// }

vector<int> str(26,0);
vector<int> end(26,0);

vector<int> eq(26,0);

for(int i=0; i<n; i++){
string s= A[i];

if(s[0]==s[1]){
    eq[s[0]-'a']++;
}

else{
    str[s[0]-'a']++;
    end[s[1]-'a']++;

}

int sc, ec, extra; sc=ec=extra=0;

//  for(int i=0; i<26; i++){
//     if(eq[i]){
//         if(str[i]==0 || end[i]==0){
// extra++;
//         }
//     }
//  }

 
 for(int i=0; i<26; i++){
        
        sc+=max(0,str[i]-end[i]);
        ec+=max(0,end[i]-str[i]);
 }

 for(int i=0; i<26; i++){
   if((str[i]==0 && end[i]==0) && eq[i]!=0){
    if(sc<ec)sc++;
    else ec++;
   }
 }

 



//  extra+=min(sc, ec);


if(sc>1 || ec>1 ) ans+='0';
else {
    ans+='1';
}
}

   


return ans;

}

int main(){
    vector<string> A= {"he", "ll", "lo", "el"};
    vector <string> B= {"ee", "ea", "eg"};
    vector<string> C= {"ab", "ba", "bq" };

    cout<<solution(A)<<endl;
    cout<<solution(B)<<endl;
    cout<<solution(C)<<endl;
}
