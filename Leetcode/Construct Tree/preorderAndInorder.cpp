#include <bits/stdc++.h>
using namespace std;

struct Treenode{
  Treenode* left;
  Treenode* right;
  int val;

  Treenode(int val_){
    val=val_;
  }
};

Treenode* buildTree(vector<int> &preorder, vector<int> &inorder){

    map<int,int> inMap;
    int n=preorder.size();
    int m=inorder.size();

    for(int i=0; i<n; i++){
        inMap[inorder[i]]=i;
    }

    Treenode* root= buildTree(preorder, 0, n, i)
}

Treenode* buildTree(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, map<int,int> inMap){

    if(prestart>preend || instart>inend) return NULL;

    Treenode* root= new Treenode(preorder[prestart]);

    int inroot = inMap(root->val);
    int numsLeft= inroot
}

int main(){
    return 0;
}