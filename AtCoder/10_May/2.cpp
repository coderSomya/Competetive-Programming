#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w; cin>>h>>w;
    vector<vector<char>> v(h,vector<char>(w));

    for(int i=0; i<h; i++){
        for(int j=0;j<w; j++){
            int x; cin>>x;
            if(x==0) v[i][j]='.';
          
            else {
                x--;
                v[i][j]='A'+x;
            }
        }
    }

    for(int i=0;i<h; i++){
        for(int j=0; j<w; j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }

}