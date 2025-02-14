#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct trie{
    trie* node[10];
    bool endmark;
    int childcount=0;
    trie(){
        endmark=false;
        //precount=0;
        for(int i=0;i<10;i++){
            node[i]=nullptr;
        }
    }
};
void insert(trie* root,const string& word) {
    trie* current = root; //
    for (char ch : word) {
        int idx = ch - '0';
        if (current->node[idx] == nullptr) {
            current->node[idx] = new trie();
            current->childcount++;
        }
        current = current->node[idx];
        //current->precount++;
    }
    current->endmark = true;
}
int lcp(trie* root,const string& w){
    trie* current=root;
    int length=0;
    for(char ch:w){
        int idx=ch-'0';
        if(current->node[idx]==nullptr) break;
        current=current->node[idx];
        length++;
    }
    return length;
}
int main(){
    int n,m;
    cin>>n>>m;
    trie* root=new trie();
    vector<string>a(n),b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
        insert(root,a[i]);
    }
    int maxlength=0;
    for(int i=0;i<m;i++){
        cin>>b[i];
        maxlength=max(maxlength,lcp(root,b[i]));
    }
    
    cout<<maxlength<<endl;
}