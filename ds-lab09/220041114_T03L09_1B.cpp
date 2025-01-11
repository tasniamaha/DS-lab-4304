#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
struct trie{
    trie* node[26];
    bool endmark;
    vector<string> sugg;
    trie(){
        for(int i=0;i<26;i++){
            node[i]=nullptr;
        }
        endmark=false;
    }
};
void insert(trie* root,const string& word) {
    trie* current = root; //
    for (char ch : word) {
        int idx = tolower(ch) - 'a';
        if (current->node[idx] == nullptr) {
            current->node[idx] = new trie();
        }
        current = current->node[idx];
        if(current->sugg.size()<3){
            current->sugg.push_back(word);
        }
        sort(current->sugg.begin(),current->sugg.end());
        //current->precount++;
    }
    current->endmark = true;
}
vector<vector<string>> search(trie* root,const string& prefix){
    vector<vector<string>> result;
    trie* current=root;
    for(char ch:prefix){
        int idx=ch-'a';
        if(current->node[idx]==nullptr){
            
            break;
        }
        current=current->node[idx];
        result.push_back(current->sugg);
    }
    while(result.size()<prefix.size()){
        result.push_back({});
    }
    return result;
}
int main(){
    string s;
    getline(cin,s);
    stringstream ss(s);
    trie* root =new trie();
    string w;
    while(ss>>w){
        insert(root,w);
    }
    string p;
    cin>>p;
    vector<vector<string>> suggestion=search(root,p);
    for(int i=0;i<suggestion.size();i++){
        if(suggestion[i].empty()){
            cout<<"Null"<<endl;
        }

        else{
            for(const string& word:suggestion[i]){
                cout<<word<<" ";
            }
            cout<<endl;
        }
    }
}

