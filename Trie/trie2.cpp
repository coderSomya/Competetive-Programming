//implementation with a few more functions

#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    int ew=0;
    int sw=0;

    bool containsKey(char ch){
        return links[ch='a']!=NULL;
    }

    void put(char ch,Node *node){
    links[ch-'a']= node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }
};

class Trie{

private: 
Node* root;

public:

Trie(){
  root= new Node();
}

void insert(string &word){
    Node* node= root;

    for(int i=0; i<word.length(); i++){
       if(!node->containsKey(word[i])){
        node->put(word[i], new Node());
       }

       node=node->get(word[i]);
       node->sw++;
    }
    node->ew++;
}


int countWordsEqualTo(string &word){
   Node *node= root;
   for(int i=0; i<word.length(); i++)
   {
    if(!node->containsKey(word[i])){
        return 0;
    }

    node= node->get(word[i]);
   }

   return node->ew;
}

int countWordsStartingWith(string &word){
   Node *node= root;
   for(int i=0; i<word.length(); i++)
   {
    if(!node->containsKey(word[i])){
        return 0;
    }
    node= node->get(word[i]);
   }
   return node->sw;
}

void erase(string word){
    Node* node= root;

    for(int i=0; i<word.length(); i++){
       
        if(!node->containsKey(word[i])) return;
        node=node->get(word[i]);
        node->sw--;
    }

    node->ew--;
}
 

};


