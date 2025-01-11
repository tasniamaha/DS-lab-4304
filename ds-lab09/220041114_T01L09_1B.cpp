#include<iostream>
#include<string>
#include<sstream>
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
void display(trie* root,string pre,int level){
    
    if(root->endmark){
        //pre[level]='\0';
        cout<<pre.substr(0,level)<<" ";
    }
    for(int i=0;i<26;i++){
        if(root->node[i]!=nullptr){
            char ch=i+'a';
            pre[level]=ch;
            display(root->node[i],pre,level+1);
        }
    }
}
int main(){
    trie* root=new trie();
    string line;
    getline(cin,line);
    stringstream ss(line);
    string word;
    while(ss>>word){
        insert(root,word);
    }
    string pre(1000,'\0');
    display(root,pre,0);
    cout<<endl;
    string l;
    getline(cin,l);
    stringstream s(l);
    string w;
    while(s>>w){
        if(search(root,w)){
            cout<<"T ";
        }
        else{
            cout<<"F ";
        }
    }
    cout<<endl;
}
