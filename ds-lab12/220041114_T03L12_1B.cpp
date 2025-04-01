#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
struct graph{
    vector<vector<int>> adjlist;
    vector<string> cities;
    graph(int V) {
        adjlist.resize(V);
        cities.resize(V);
    }
    void addedge(int u,int v){
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    void bfs(string src,string dest,int k){
        int start=-1,end=-1;
        for(int i=0;i<cities.size();i++){
            if(cities[i]==src) start=i;
            if(cities[i]==dest) end=i;
        }
        if(start==-1 or end==-1){
            cout<<"NO"<<endl;
            return;
        }
        
        
        queue<pair<int,vector<int>>> q;
        vector<bool> visited(cities.size(),false);
        q.push({start,{start}});
        visited[start]=true;
        while(!q.empty()){
            auto [node,path]=q.front();
            q.pop();
            if(node==end){
                vector<string>final;
                for (int ind : path) {
                    final.push_back(cities[ind]);
                }

                for (int i = 0; i < final.size(); i++) {
                    if (i % k == 0 || i == final.size() - 1) {
                        cout << final[i] << " ";
                    }
                }
                cout << endl;
                return;
            }
            for(int neighbour:adjlist[node]){
                if(!visited[neighbour]){
                    visited[neighbour]=true;
                    vector<int>newpath=path;
                    newpath.push_back(neighbour);
                    q.push({neighbour,newpath});
                }
            }
            
        }
        cout<<"NO"<<endl;
    }
};
int main(){
    int V,E,Q;
    cin>>V>>E>>Q;
    graph g(V);
    //string c;
    for(int i=0;i<V;i++){
        
        cin>>g.cities[i];
    }
    while(E--){
        string c1,c2;
        cin>>c1>>c2;
        int u=-1,v=-1;
        for(int i=0;i<g.cities.size();i++){
            if(g.cities[i]==c1) u=i;
            if(g.cities[i]==c2) v=i;
        }
        g.addedge(u,v);
    }
    while(Q--){
        string src,dest;
        int k;
        cin>>src>>dest>>k;
        g.bfs(src,dest,k);
    }
}