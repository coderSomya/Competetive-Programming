#include <bits/stdc++.h>
using namespace std;

//backtracking
int ct;

void print(vector<vector<bool>> &grid, int n)
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]) cout<<"Q";
            else cout<<".";
        }
        cout<<endl;
    }
}

bool isSafe(vector<vector<bool>> &grid, int r, int c, int n){

   //column
   for(int i=r-1; i>=0; i--){
      if(grid[i][c]) return false;
   }

   //left diagonal
   for(int i=r-1,j=c-1; i>=0&& j>=0; i--,j--){
     if(grid[i][j]) return false;
   }

   //right diagonal
   for(int i=r-1,j=c+1; i>=0&&j<n; i--,j++){
    if(grid[i][j]) return false;
   }

   return true;

}

void countNQueen(vector<vector<bool>> &grid, int curr_row, int n){

    if(curr_row==n){
        ct++;
        print(grid, n);
        cout<<"\n\n";
    }

    for(int i=0; i<n; i++){
    if(isSafe(grid, curr_row, i, n)){
        grid[curr_row][i]=true;
        countNQueen(grid, curr_row+1, n);
        grid[curr_row][i]=false;
    }
    }


}

int main(){

    int n; cin>>n;
    vector<vector<bool>>grid(n, vector<bool>(n,0));
   
   ct=0;
   countNQueen(grid,0,n);
   cout<<ct<<endl;
}
