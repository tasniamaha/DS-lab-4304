#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int a;
    unordered_map<int,int> freq;
    vector<int> num;
    while(1){
        cin>>a;
        if(a==-1) break;
        num.push_back(a);
        freq[a]++;
    }
    int target ;
    cin>>target;
    bool found=false;
    bool first=true;
    for(auto& entry:freq){
        int curr=entry.first;
        int comp=target-curr;
        if(freq.find(comp)!=freq.end()){
            if(curr==comp && freq[curr]>1){
                if(!first) cout<<", ";
                cout<<"("<<curr<<","<<curr<<")";
                found=true;
                first=false;
            }
            else if(curr<comp){
                if(!first) cout<<", ";
                cout<<"("<<curr<<","<<comp<<")";
                found=true;
                first=false;
            }
        }
    }
    cout<<endl;
    if(!found) cout<<"No pairs found"<<endl;
}