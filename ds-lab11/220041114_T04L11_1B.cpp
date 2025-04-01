#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
bool pathexists(int source,int destination,vector<vector<int>>adj){
    int v=adj.size();
    vector<bool>visited(v,false);
    stack<int> stck;
    stck.push(source);
    visited[source]=true;
    while(!stck.empty()){
        int n=stck.top();
        stck.pop();
        if(n==destination) return true;
        for(int neighbour:adj[n]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                stck.push(neighbour);
            }
        }
    }
    return false;
}

int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adjlist(V+1);
    while(E--){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
    }
    int src,dest;
    cin>>src>>dest;
    
    if(pathexists(src,dest,adjlist)) {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    //printadjlist(adjlist,V);
}