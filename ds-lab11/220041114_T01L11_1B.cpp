#include<iostream>
#include<vector>
using namespace std;

void printadjlist(vector<vector<int>> adjlist,int V){
    cout<<"Adjacency List:\n";
    for(int i=0;i<V;i++){
        cout<<i+1<<": ";
        for(int neighbour:adjlist[i]){
            cout<<neighbour<<" ";
        }
        cout<<endl;
    }
}

void printadjmatrix(vector<vector<int>> adjmatrix,int V){
    cout<<"Adjacency Matrix:\n";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<adjmatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adjlist(V);
    vector<vector<int>> adjmat(V,vector<int>(V,0));
    while(E--){
        int u,v;
        cin>>u>>v;
        adjlist[u-1].push_back(v);
        adjlist[v-1].push_back(u);
        adjmat[u-1][v-1]=1;
        adjmat[v-1][u-1]=1;
    }
    printadjlist(adjlist,V);
    printadjmatrix(adjmat,V);
}
