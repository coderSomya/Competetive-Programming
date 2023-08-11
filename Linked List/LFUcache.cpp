#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key, value, cnt;
    Node *next;
    Node *prev;
    
    Node(int _key, int _value){
        key=_key;
        value=_value;

        cnt=1;
    }


};

struct List{
  int size;
  Node* head;
  Node* tail;

  List(){
    head=new Node(0,0);
    tail=new Node(0,0);

    head->next= tail;
    tail->prev= head;

    size=0;
  }


  void addFront(Node *node){
    Node* temp = head->next;
    node->next = temp;
    temp->prev=node;
    head->next=node;
    node->prev= head;
    size++;
  }

  void removeNode(Node* delnode){
    Node* delprev= delnode->prev;
    Node* delnext= delnode->next;

    delprev->next=delnext;
    delnext->prev=delprev;

    size--;
  }
};

class LFUcache{
   
   map<int, Node*> keynode;
   map<int, List*> freqlist;

   int cap; int mini; int size;

   void updateFreq(Node* node){
    keynode.erase(node->key);
    freqlist[node->cnt]->removeNode(node);

    if(node->cnt == mini && freqlist[mini]->size==0){
        mini++;
    }

    List* nextHigherFreqList = new List();
    node->cnt++;

    if(freqlist.find(node->cnt)!=freqlist.end()){
        nextHigherFreqList=freqlist[node->cnt];
    }
    nextHigherFreqList->addFront(node);
    freqlist[node->cnt]=nextHigherFreqList;
    keynode[node->key]=node;
   }

   int get(int key){
    if(keynode.find(key)!=keynode.end()){
        updateFreq(keynode[key]);
        return keynode[key]->value;
    }
    return -1;
   }

   void put(int key, int value){
    if(keynode.find(key)!=keynode.end()){
        Node* node= keynode[key];
        node->value=value;
        updateFreq(node);
    }
    else{
        if(size==cap){
            List *list= freqlist[mini];
            keynode.erase(list->tail->prev->key);
            freqlist[mini]->removeNode(list->tail->prev);
            size--;
        }
        size++;
        mini=1;
        List *listfreq=new List();
        if(freqlist.find(mini)!=freqlist.end()){
            listfreq=freqlist[mini];
        }

        Node* node= new Node(key, value);
        listfreq->addFront(node);
        keynode[key]=node;
        freqlist[1]->addFront(node);
    }
   }
};

int main(){
    return 0;
}