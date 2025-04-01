<<<<<<< HEAD
#include<iostream>
#include<vector>
using namespace std;
vector<int>parent,rnk;
void makeset(int n){
    parent.resize(n);
    rnk.resize(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
}
int find(int u){
    if(parent[u]==u){
        return parent[u];
    }
    else return parent[u]=find(parent[u]);
}
void uni(int u,int v){
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
    }
    
}
void print(){
    for(int i=0;i<parent.size()&&i<rnk.size();i++){
        cout<<parent[i]<<"("<<rnk[i]<<")"<<" ";
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
        else if(choice==3){
            int u,v;
            cin>>u>>v;
            uni(u,v);
            print();
        }
        else{
            print();
        }
    }
}
=======
#include<iostream>
#include<vector>
using namespace std;
vector<int>parent,rnk;
void makeset(int n){
    parent.resize(n);
    rnk.resize(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
}
int find(int u){
    if(parent[u]==u){
        return parent[u];
    }
    else return parent[u]=find(parent[u]);
}
void uni(int u,int v){
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
    }
    
}
void print(){
    for(int i=0;i<parent.size()&&i<rnk.size();i++){
        cout<<parent[i]<<"("<<rnk[i]<<")"<<" ";
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
        else if(choice==3){
            int u,v;
            cin>>u>>v;
            uni(u,v);
            print();
        }
        else{
            print();
        }
    }
}
>>>>>>> aa9c986 (Added new files)
