#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;
int main(){
    int t,m,n;
    cin>>t>>m>>n;
    unordered_map<string,vector<string>> maze;
    while(t--){
        string name;
        cin>>name;
        vector<vector<char>> map(m,vector<char>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>map[i][j];
            }
        }
        string input="";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                input+=map[i][j];
            }
        }
        maze[input].push_back(name);

    }
    for(auto& entry:maze){
        for(const string& name:entry.second){
            cout<<name<<" ";
        }
        cout<<endl;
    }
}