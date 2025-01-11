#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<sstream>
using namespace std;
struct trie{
    trie* node[2];
    bool endmark;
    trie(){
        node[0]=nullptr;
        node[1]=nullptr;
        endmark=false;
    }
};

void insert(trie* root,int n){
    trie* current=root;
    for(int i=31;i>=0;i--){
        int bit=(n>>i)&1; 
        if(current->node[bit]==nullptr){
            current->node[bit]=new trie();
        }
        current=current->node[bit];
    }
    current->endmark=true;
}
int max_xor(trie* root,const vector<int>& num){
    int ma=0;
    for(int i=0;i<num.size();i++){
        int curr=0;
        trie* current=root;
        for(int j=31;j>=0;j--){
            int bit=(num[i]>>j)&1;
            int o=1-bit; 
            if(current->node[o]){
                curr|=(1<<j);
                current=current->node[o];
            }
            else{
                //curr=(1<<j);
                current=current->node[bit];
            }
        }
        ma=max(ma,curr);
    }
    return ma;
}
int main(){
    string s;
    getline(cin,s);
    stringstream ss(s);
    trie* root=new trie();
    int n;
    vector<int> nums;
    while(ss>>n){
        nums.push_back(n);
        insert(root,n);
    }
    cout<<max_xor(root,nums)<<endl;
}