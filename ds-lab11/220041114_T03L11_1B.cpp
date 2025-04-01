#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>topsort(int v,vector<vector<int>>adj){
    vector<int>indegree(v),result;
    queue<int>q;
    for(int i=0;i<v;i++){
        for(int V:adj[i]){
            indegree[v]++;
        }
    }
    for(int i=0;i<v;i++){
        if(indegree[i]==0) q.push(i);
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        result.push_back(u);
        for(int V:adj[u]){
            indegree[V]--;
            if(indegree[V]==0){
                q.push(V);
            }
        }
    }
    if(result.size()!=v) return {};
    else return result;
}
int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj(V);
    while(E--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);

    }
    vector<int> res=topsort(V,adj);
    if(res.empty()){
        cout<<"[ ]"<<endl;
    }
    else {
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
}
