#include<iostream>
#include<string>
#include<sstream>
#include<unordered_map>
using namespace std;
struct trie{
    trie* node[26];
    bool endmark;
    //int precount;
    trie(){
        endmark=false;
        //precount=0;
        for(int i=0;i<26;i++){
            node[i]=nullptr;
        }
    }
};
void insert(trie* root,const string& word) {
    trie* current = root; //
    for (char ch : word) {
        int idx = ch - 'a';
        if (current->node[idx] == nullptr) {
            current->node[idx] = new trie();
        }
        current = current->node[idx];
        //current->precount++;
    }
    current->endmark = true;
}
bool search(trie* root,const string& word){
    trie* current=root;
    for(int i=0;i<word.length();i++){
        int idx = word[i] - 'a';
        if (current->node[idx] == nullptr) {
            return false;
        }
        current = current->node[idx]; 
    }
    return current->endmark;
}
bool wordseg(string str,trie* root,unordered_map<string,bool>&m){
    int size=str.length();
    if(size==0) return true;
    if(m.find(str)!=m.end()) return m[str];
    for(int i=1;i<=size;i++){
        if(search(root,str.substr(0,i)) && wordseg(str.substr(i),root,m)) return m[str]=true;
    }
    return m[str]=false;
}
int main(){
    string word;
    trie* root=new trie();
    unordered_map<string,bool>memo;
    while(1){
        cin>>word;
        if(word=="-1") break;
        
        insert(root,word);
    }
    string input;
    cin>>input;
    if(wordseg(input,root,memo)){
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }
}