#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;
int main(){
    string s;
    while(getline(cin,s)){
        deque<char> ans;
        bool inbrac=false;
        string temp;
        for(int i=0;i<s.length();i++){
            if(s[i]=='['){
                inbrac=true;
                temp.clear();
            }
            else if(s[i]==']'){
                inbrac=false;
                reverse(temp.begin(), temp.end());
                for(auto tc :temp){
                    
                    ans.push_front(tc);
                    
                }
            }
            else{
                if(inbrac) temp.push_back(s[i]);
                else ans.push_back(s[i]);
            }
        }
        for(char c: ans){
            cout<<c;
        }
        cout<<endl;
    }
}