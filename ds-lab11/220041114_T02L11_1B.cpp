#include<iostream>
#include<vector>
using namespace std;

int main(){
    int V,E;
    cin>>V>>E;
    vector<int>deg(V);
    while(E--){
        int u,v;
        cin>>u>>v;
        deg[u-1]++;
        deg[v-1]++;
    }
    int d=deg[0];
    bool regular=true;
    for(int i=1;i<deg.size();i++){
        if(deg[i]==d){
            regular=false;
            break;
        }
    }
    if(regular) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}