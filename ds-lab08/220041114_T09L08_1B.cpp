#include<iostream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    string line;
    unordered_map<string,string> dictionary;
    while(true){
        getline(cin,line);
        stringstream ss(line);
        if(line.empty()){
            break;
        }
        string mean,word;
        ss>>mean>>word;
        dictionary[word]=mean;
    }
    string s;
    while(true){
        getline(cin,s);
        if(s.empty()){
            break;
        }
        if(dictionary.count(s)){
            cout<<dictionary[s]<<endl;
        }
        else{
            cout<<"eh"<<endl;
        }
    }
}