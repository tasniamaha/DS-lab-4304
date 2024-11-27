#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<unordered_map>
#include<cctype>
using namespace std;
int main(){
    string input;
    getline(cin,input);
    string ans;
    for(int i=0;i<input.length();i++){
        if(!ispunct(input[i])){
           ans+=input[i];
        }
    }
    input=ans;
    unordered_map<string,int> wordcount;
    stringstream ss(input);
    string word;
    while(ss>>word){
        wordcount[word]++;
    }

    for(auto& entry:wordcount){
        if(entry.second>1){
            cout<<entry.first<<" "<<entry.second<<endl;
        }
    }
}