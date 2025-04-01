#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int q;
    cin>>q;
    vector<vector<int>> prefixfreq;
    prefixfreq.assign(s.size()+1,vector<int>(26,0));
    for(int i=0;i<s.size();i++){
        prefixfreq[i+1]=prefixfreq[i];
        prefixfreq[i+1][s[i]-'a']++;
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        vector<int>freq(26,0);
        for(int i=0;i<26;i++){
            freq[i]=prefixfreq[r+1][i]-prefixfreq[l][i];
        }
        int maxfreq=0;
        char maxchar='a';
        for(int i=0;i<freq.size();i++){
            if(freq[i]>maxfreq){
                maxfreq=freq[i];
                maxchar='a'+i;
            }
        }
        cout<<maxchar<<endl;
    }
}