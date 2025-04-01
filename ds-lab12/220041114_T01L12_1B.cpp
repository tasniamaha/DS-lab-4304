#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;
struct graph{
    vector<vector<int>>adjlist;
    int V;
    vector<int>distance;
    vector<int>pred;
    vector<string>colour;
    vector<pair<int,int>>bfs_edge;
    graph(int vert){
        V=vert;
        adjlist.resize(V+1);
        
        distance.resize(V+1,-1);
        pred.resize(V+1,-1);
        colour.resize(V+1,"white");
    }
    void addedge(int u,int v){
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    void bfs(int s){
        queue<int>q;
        q.push(s);
        distance[s]=0;
        colour[s]="grey";
        vector<int>bfs_order;
        while(!q.empty()){
            int n=q.front();
            bfs_order.push_back(n);
            q.pop();
            for(int V:adjlist[n]){
                if(colour[V]=="white"){
                    colour[V]="grey";
                    distance[V]=distance[n]+1;
                    pred[V]=n;
                    q.push(V);
                    bfs_edge.push_back({n,V});
                }
            }
            colour[n]="black";
        }
        cout<<"Adjacency list:\n";
        for(int i=1;i<=V;i++){
            cout<<i<<": ";
            for(int neighbour:adjlist[i]){
                cout<<neighbour<<" ";
            }
            cout<<endl;
        }
        cout<<"\nBFS order: ";
        for(int node:bfs_order){
            cout<<node<<" ";
        }
        cout<<endl;
        cout<<"Distance from source: \n";
        for (int i = 1; i <= V; i++) {
            cout << i << "(" << distance[i] << ") ";
        }
        cout << "\n";
        cout<<"Paths from source:\n";
        for (int i =1;i<=V;i++) {
            if (distance[i]!=-1) {
                vector<int>path;
                int current=i;
                while (current!=-1) {
                    path.push_back(current);
                    current=pred[current];
                }
                reverse(path.begin(),path.end());
                cout<<i<<": ";
                for(int j = 0;j < path.size(); j++) {
                    if (j > 0) cout << "->";
                    cout << path[j];
                }
                cout << "\n";
            }
        }
        cout<<"Edges of BFS tree:\n";
        for(auto it:bfs_edge){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
};
int main(){
    int V,E,s;
    cin>>V>>E>>s;
    graph g(V);
    while(E--){
        int u,v;
        cin>>u>>v;
        g.addedge(u,v);
    }
    g.bfs(s);
}