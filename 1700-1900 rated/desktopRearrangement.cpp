#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n,m,q;
  cin>>n>>m>>q;

  vector<vector<int>> grid(n+1, vector<int>(m+1,0));

  int total=0;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        char ch; cin>>ch;
        if(ch=='.') grid[i][j]=0;
        else grid[i][j]=1;

        total+=grid[i][j];
    }
  }
  
  set<pair<int,int>> good;
  set<pair<int,int>> bad;

   int last_row=total%n;
      int last_col=total/n;
      if(last_row!=0){
        last_row--;
      }
      else{
        last_row=n-1;
        last_col--;
      }

  for(int i=0; i<n; i++) for(int j=0; j<m; j++) if(grid[i][j]==1){
    if(j<last_col || (j==last_col && i<=last_row)) good.insert({i,j});
    else bad.insert({i,j});
  }
  

  while(q--){

    int x, y; cin>>x>>y;
    x--; y--;
    //do something

    if(grid[x][y]){
      if(good.find({x,y})!=good.end()) good.erase({x,y});
      else if(bad.find({x,y})!=bad.end()) bad.erase({x,y});

      int last_row=total%n;
      int last_col=total/n;
      if(last_row!=0){
        last_row--;
      }
      else{
        last_row=n-1;
        last_col--;
      }
     
     pair<int,int> last={last_row, last_col};
     if(good.find(last)!=good.end()){
        good.erase(last);
        bad.insert(last);
     }

     grid[x][y]=0;

     total--;
    }

    else{

        total++;
          int last_row=total%n;
      int last_col=total/n;
      if(last_row!=0){
        last_row--;
      }
      else{
        last_row=n-1;
        last_col--;
      }
           pair<int,int> last={last_row, last_col};
        if(bad.find(last)!=bad.end()){
            bad.erase(last); good.insert(last);
        }
       if(y<last_col || (y==last_col && x<=last_row)){
        good.insert({x,y});
       }
       else bad.insert({x,y});

        grid[x][y]=1;

    }
// cout<<"GOOD = "<<endl;
//    for(auto x: good) cout<<x.first<<","<<x.second<<" ";
//    cout<<endl;
//    cout<<"BAD = "<<endl;
// for(auto x: bad) cout<<x.first<<","<<x.second<<" ";
//    cout<<endl;

    cout<<bad.size()<<endl;
  }



  


}

int main(){
     solve();

    return 0;
}