#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct trie{
    trie* node[52];
    bool endmark;
    int wordcount;
    trie(){
        endmark=false;
        wordcount=0;
        for(int i=0;i<52;i++){
            node[i]=nullptr;
        }
    }

};
int getindex(char c){
    if(c>='a' and c<='z'){
        return c-'a';
    }
    else return c-'A'+26;
}
void insert(trie* root,const string& word) {
    trie* current = root; 
    for (char ch : word) {
        int idx=getindex(ch);
        if(isupper(ch)){
            if (current->node[idx] == nullptr) {
                current->node[idx] = new trie();
            }
            current = current->node[idx];
        }
    }
    current->endmark = true;
}
bool search(trie* root,const string& abb){
    trie* current=root;
    int abind=0;
    while(abind<abb.length() && current!=nullptr){
        char curr=abb[abind];
        int idx=getindex(curr);
        if(current->node[idx]){
            current=current->node[idx];
            abind++;
        }
        else if(isupper(curr)) return false;
        else abind++;
    }
    return abind==abb.length();
}
int main(){
    string word;
    
    int count=0;
    vector<string>w;
    while(cin>>word && word!="-1"){
       w.push_back(word);
       
    }
    //cin.ignore();
    string abbreviation;
    cin>>abbreviation;
    for(const string& words:w){
        trie* root=new trie();
        insert(root,words);
        if(search(root,abbreviation)) cout<<"T"<<" ";
        else cout<<"F"<<" ";
        delete root;
    }
    cout<<endl;
}