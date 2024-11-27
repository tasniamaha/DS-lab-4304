#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    string sub;
    unordered_map<string,int> subcount;
    for(int i=0;i<=s.length()-10;i++){
        string sub=s.substr(i,10);
        subcount[sub]++;
    }
    vector<string>res;
    for(auto& entry:subcount){
        if(entry.second>1){
            cout<<entry.first<<", ";
            
        }
        
    }
    cout<<endl;
}