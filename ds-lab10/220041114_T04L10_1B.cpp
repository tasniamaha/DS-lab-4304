<<<<<<< HEAD
#include<iostream>
#include<vector>
#include<utility>
using namespace std;
struct dsu{
    vector<int>parent,rnk;
    
    dsu(int n){
        
        parent.resize(n);
        rnk.resize(n,1);
        
        
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int u){
        if(parent[u]==u) return parent[u];
        else return parent[u]=find(parent[u]);
    }
    bool uni(int u,int v){
        int ri=find(u);
        int rj=find(v);
        if(ri!=rj){
            if(rnk[ri]<=rnk[rj]){
                parent[ri]=rj;
                
                
            }
            else{
                parent[rj]=ri;
                
                
            }
            if(rnk[ri]==rnk[rj]){
                rnk[rj]++;
            }
            return true;
        }
        return false;
    }
    bool connected(int u,int v){
        return find(u)==find(v);
    }
};
int main(){
    int n;
    cin>>n;
    dsu d(n);
    vector<pair<int,int>> road(n-1);
    for(int i=0;i<n-1;i++){
        cin>>road[i].first>>road[i].second;
    }
    vector<pair<int,int>> newroad,oldroad;
    for(auto r:road){
        if(!d.uni(r.first-1,r.second-1)){
            oldroad.push_back(r);
        }

    }
    vector<int>comp;
    for(int i=0;i<n;i++){
        if(d.find(i)==i){
            comp.push_back(i);
        }
    }
    for(size_t i=1;i<comp.size();i++){
        newroad.emplace_back(comp[i-1]+1,comp[i]+1);
    }
    cout<<oldroad.size()<<endl;
    for(size_t i=0;i<oldroad.size();i++){
        cout<<oldroad[i].first<<" "<<oldroad[i].second<<"  ";
        if(i<newroad.size()){
            cout<<newroad[i].first<<' '<<newroad[i].second<<endl;
        }
        else{
            cout<<comp[0]+1<<' '<<comp.back()+1<<endl;
        }
    }
    
    
=======
#include<iostream>
#include<vector>
#include<utility>
using namespace std;
struct dsu{
    vector<int>parent,rnk;
    
    dsu(int n){
        
        parent.resize(n);
        rnk.resize(n,1);
        
        
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int u){
        if(parent[u]==u) return parent[u];
        else return parent[u]=find(parent[u]);
    }
    bool uni(int u,int v){
        int ri=find(u);
        int rj=find(v);
        if(ri!=rj){
            if(rnk[ri]<=rnk[rj]){
                parent[ri]=rj;
                
                
            }
            else{
                parent[rj]=ri;
                
                
            }
            if(rnk[ri]==rnk[rj]){
                rnk[rj]++;
            }
            return true;
        }
        return false;
    }
    bool connected(int u,int v){
        return find(u)==find(v);
    }
};
int main(){
    int n;
    cin>>n;
    dsu d(n);
    vector<pair<int,int>> road(n-1);
    for(int i=0;i<n-1;i++){
        cin>>road[i].first>>road[i].second;
    }
    vector<pair<int,int>> newroad,oldroad;
    for(auto r:road){
        if(!d.uni(r.first-1,r.second-1)){
            oldroad.push_back(r);
        }

    }
    vector<int>comp;
    for(int i=0;i<n;i++){
        if(d.find(i)==i){
            comp.push_back(i);
        }
    }
    for(size_t i=1;i<comp.size();i++){
        newroad.emplace_back(comp[i-1]+1,comp[i]+1);
    }
    cout<<oldroad.size()<<endl;
    for(size_t i=0;i<oldroad.size();i++){
        cout<<oldroad[i].first<<" "<<oldroad[i].second<<"  ";
        if(i<newroad.size()){
            cout<<newroad[i].first<<' '<<newroad[i].second<<endl;
        }
        else{
            cout<<comp[0]+1<<' '<<comp.back()+1<<endl;
        }
    }
    
    
>>>>>>> aa9c986 (Added new files)
}