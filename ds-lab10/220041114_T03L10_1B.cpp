#include<iostream>
#include<vector>
using namespace std;
vector<int>parent,rnk;
struct dsu{
    vector<int>parent,rnk,sz;
    int max_size;
    int num_of_comp;
    dsu(int n){
        max_size=1;
        num_of_comp=n;
        parent.resize(n);
        rnk.resize(n,1);
        sz.resize(n,1);
        
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int u){
        if(parent[u]==u) return parent[u];
        else return parent[u]=find(parent[u]);
    }
    void uni(int u,int v){
        int ri=find(u);
        int rj=find(v);
        if(ri!=rj){
            if(rnk[ri]<=rnk[rj]){
                parent[ri]=rj;
                sz[rj]+=sz[ri];
                max_size=max(max_size,sz[rj]);
            }
            else{
                parent[rj]=ri;
                sz[ri]+=sz[rj];
                max_size=max(max_size,sz[ri]);
            }
            if(rnk[ri]==rnk[rj]){
                rnk[rj]++;
            }
            num_of_comp--;
        }
        
    }
    bool connected(int u,int v){
        return find(u)==find(v);
    }
};
int main(){
    int n,q;
    cin>>n>>q;
    dsu d(n);
    while(q--){
        int u,v;
        cin>>u>>v;
        d.uni(u-1,v-1);
        cout<<d.num_of_comp<<' '<<d.max_size<<endl;
    }
}