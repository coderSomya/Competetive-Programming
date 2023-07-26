#include <bits/stdc++.h>
using namespace std;

struct node{
    node *links[26];
    int val=0;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void addKey(char ch){
        links[ch-'a']=new node();
    }
};

class Trie{
   
   public: node* root;

   Trie(){
    root = new node();
   }

   public:

   void insert(string word, int freq){
    node* Node = root;

    for(int i=0; i<word.length(); i++){
        if(!(Node->containsKey(word[i]))){
            Node->addKey(word[i]);
        }
        Node=Node->links[word[i]-'a'];
        Node->val+=freq;
      
    }
   }

   int count(string word){
    int ans=0;

    node* Node= root;

    for(int i=0; i<word.length(); i++){
          if(!Node->containsKey(word[i])) return ans;
          Node = Node->links[word[i]-'a'];
    }

    return Node->val;
   }
};

void solve(){

    int q;  cin>>q;
    Trie trie;

    for(int i=0; i<q; i++){
        char ch; cin>>ch;

        if(ch=='I'){
            string s; cin>>s;
            int freq; cin>>freq;

            trie.insert(s, freq);
        }
        else{
            string t; cin>>t;

            int ans=trie.count(t);
            cout<<ans<<endl;
        }
    }
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}