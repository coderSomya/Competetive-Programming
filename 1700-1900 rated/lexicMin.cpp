#include <bits/stdc++.h>
using namespace std;

void fill(string &s, int start, int arr[]){
   
   for(int i=start; i<26; i++){
     for(int j=0; j<arr[i]; j++){
        s+= 'a'+i;
     }
   }


}

void solve(){
    string s; cin>>s;
    string pref="";
    string suff="";

    int freq[26]={0};
    for(char ch: s){
        freq[ch-'a']++;
    }

    for(int i=0; i<26; i++){
       for(int j=0; j<freq[i]/2; j++){
        pref+='a'+i;
       }
       for(int j=0; j<freq[i]/2; j++){
        suff+='a'+i;
       }

       freq[i]-= 2*(freq[i]/2);

       if(freq[i]){
          
          int ct=0; int idx=-1;
          for(int k=i+1; k<26; k++){
            ct+= (freq[k]!=0);
            idx=(freq[k]!=0 ? k: idx);
          }

          if(ct>1){
             //add everything in sorted order to pref
             fill(pref, i+1,freq);
             suff+='a'+i;
             break;
          }

          else{

            if(idx!=-1){
                for(int k=0; k<freq[idx]/2; k++){
                    pref+='a'+idx;
                }
                 for(int k=0; k<freq[idx]/2; k++){
                    suff+='a'+idx;
                }

                freq[idx]-=2*(freq[idx]/2);
                if(freq[idx]) pref+='a'+idx;
            }

            pref+='a'+i; break;

          }
       }
    }


    reverse(suff.begin(), suff.end());
    pref+=suff;
    cout<<pref<<endl;
}

int main(){
    int t;cin>>t;
    while(t--) solve();

    return 0;
}