
#include<iostream>
#include<vector>
using namespace std;
vector<int>parent;
void makeset(int n){
    parent.resize(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
}
int find(int u){
    if(parent[u]==u) return parent[u];
    else return find(parent[u]);
}
void uni(int u,int v){
    int ri=find(u);
    int rj=find(v);
    if(ri!=rj){
        parent[rj]=ri;
    }
}
void print(){
    for(int i=0;i<parent.size();i++){
        cout<<parent[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    while(true){
        int choice;
        cin>>choice;
        if(choice==1){
            makeset(n);
            print();
        }
        else if(choice==2){
            int u;
            cin>>u;
            cout<<find(u)<<endl;
        }
        else {
            int u,v;
            cin>>u>>v;
            uni(u,v);
            print();
        }
    }

}