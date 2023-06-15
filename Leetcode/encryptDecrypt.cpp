/*
problem link->
https://leetcode.com/problems/encrypt-and-decrypt-strings/
*/

#include <bits/stdc++.h>
using namespace std;

class Encrypter {
private: 
  unordered_map<char,string> mp;
  unordered_map<string, int> freq;
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i=0; i<keys.size(); i++){
        mp[keys[i]]=values[i];
        }

        //encrypt all the words in dictionary
        for(int i=0; i<dictionary.size(); i++){
            string s1=encrypt(dictionary[i]); 
            freq[s1]++;
        }

    }
    
    string encrypt(string word1) {

        string s1="";
        int n=word1.length();
        for(int i=0; i<n; i++){
            if(mp.find(word1[i])==mp.end()) return "";

            else s1+= mp[word1[i]];
        }

        return s1;
        
    }
    
    int decrypt(string word2) {
         
         if(freq.find(word2)==freq.end()) return 0;
         else return freq[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */