#include<iostream>
#include<string>
#include<sstream>
using namespace std;
struct trie{
    trie* node[26];
    bool endmark;
    int precount;
    trie(){
        endmark=false;
        precount=0;
        for(int i=0;i<26;i++){
            node[i]=nullptr;
        }
    }
};
void insert(trie* root,const string& word){
    trie* current=root;
    for(int i=0;i<word.length();i++){
        int idx=word[i]-'a';
        if(current->node[idx]==nullptr){
            current->node[idx]=new trie();
        }
        current=current->node[idx];
        current->precount++;
    }
    current->endmark=true;
}
int prefixcount(trie* root,string pre){
    trie* current=root;
    for(int i=0;i<pre.length();i++){
        int idx=pre[i]-'a';
        if(current->node[idx]==nullptr){
            return 0;
        }
        current=current->node[idx];
    }
    return current->precount;
}
int main(){
    trie* root=new trie();
    int t,q;
    cin>>t>>q;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        for(char& c:s){
            c=tolower(c);
        }
        insert(root,s);
    }
    while(q--){
        string p;
        getline(cin,p);
        for(char& ch:p){
            ch=tolower(ch);
        }
        cout<<prefixcount(root,p)<<endl;
    }
}
