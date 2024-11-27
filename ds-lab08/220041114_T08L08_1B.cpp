#include<iostream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    string input;
    getline(cin,input);
    string req;
    getline(cin,req);
    unordered_map<char,int> charcount;
    for(int i=0;i<req.length();i++){
        charcount[req[i]]=1;
    }
    string unique;
    for(auto& entry:charcount){
        unique+=entry.first;
    }
    sort(unique.begin(),unique.end());
    stringstream ss(input);
    
    string word;
    while(ss>>word){
        unordered_map<char,int> a;
        for(int i=0;i<word.length();i++){
            a[word[i]]=1;
        }
        string ans;
        for(auto& entry:a){
        ans+=entry.first;
        }
        sort(ans.begin(),ans.end());
        if(ans==unique){
            cout<<word<<" ";
        }

    }
    cout<<endl;
}