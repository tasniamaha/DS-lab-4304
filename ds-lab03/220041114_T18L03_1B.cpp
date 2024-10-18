#include<iostream>
#include<vector>
using namespace std;
void minheapify(int i,vector<int> &ar,int s){
    int l=2*i;
    int r=2*i+1;
    int smallest=i;
    if(l<=s && ar[l]<ar[smallest]){
        smallest=l;
    }
    if(r<=s && ar[r]<ar[smallest]){
        smallest=r;
    }
    if(smallest!=i){
        swap(ar[smallest],ar[i]);
        minheapify(smallest,ar,s);
    }
}
void buildminheap(vector<int> &ar,int s){
    for(int i=(s/2);i>=1;i--){
        minheapify(i,ar,s);
    }
}
void heapsort(vector<int> &ar,int s){
    buildminheap(ar,s);
    for(int i=s;i>1;i--){
        swap(ar[1],ar[i]);
        minheapify(1,ar,i-1);
    }
}
void display(const vector<int> &ar,int s){
    for(int i=1;i<=s;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int x;
    vector<int> a(1);
    while(1){
        cin>>x;
        if(x==-1) break;
        a.push_back(x);
    }
    int s=a.size()-1;
    buildminheap(a,s);
    cout<<"Min Heap: ";
    display(a,s);
    heapsort(a,s);
    cout<<"Sorted: ";
    display(a,s);
}