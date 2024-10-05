#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void min_heapify(int i,vector<int> &arr,int s){
    int l=2*i;
    int r=2*i+1;
    int smallest=i;
    if(l<s && arr[l]<arr[smallest]){
        smallest=l;
    }
    
    if(r<s && arr[r]<arr[smallest]){
        smallest=r;
    }
    
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        min_heapify(smallest,arr,s);
    }
}
void build_minheap(vector<int> &arr,int s){
    for(int i=(s/2);i>=1;i--){
        min_heapify(i,arr,s);
    }
}
int heap_minimum(vector<int> &arr){
    return arr[1];
}
int extract_heap_min(vector<int> &arr,int &s){
    if(s<1){
        cout<<"Underflow"<<endl;
    }
    int m=arr[1];
    arr[1]=arr[s];
    s--;
    min_heapify(1, arr, s);
    return m;
}
void min_heap_insert(vector<int> &arr,int &s,int k){
    s++;
    arr[s]=k;
    int id=s;
    int parent=(id)/2;
    while(id>1 && arr[parent]>arr[id]){
        swap(arr[parent],arr[id]);
        id=parent;
        parent=id/2;
    }
}
void decrease_key(int i,int k,vector<int> &arr,int &s){
    arr[i]-=k;
    min_heapify(i,arr,s);
}
void increase_key(int i,int k,vector<int> &arr,int &s){
    arr[i]+=k;
    int id=s;
    int parent=(id)/2;
    
    while(id>1 && arr[parent]>arr[id]){
        swap(arr[parent],arr[id]);
        id=parent;
        parent=id/2;
    }
}
void display(vector <int> &arr,int s){
    for(int i=1;i<=s;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int x;
    vector<int> a(1000);
    int s=0;
    while(1){
        cin>>x;
        if(x==-1) break;
        a[++s]=x;
    }
    

    build_minheap(a,s);
    cout<<"Min Heap :";
    display(a,s);
    int b;
    while(1){
        cin>>b;
        if(b==1){
            cout<<heap_minimum(a)<<endl;
            display(a,s);
        }
        else if(b==2){
            cout<<extract_heap_min(a,s)<<endl;
            display(a,s);
        }
        else if(b==3){
            int key;
            cin>>key;
            min_heap_insert(a,s,key);
            display(a,s);
        }
        else if(b==4){
            int id,key;
            cin>>id>>key;
            decrease_key(id,key,a,s);
            display(a,s);
        }
        else if(b==5){
            int id,key;
            cin>>id>>key;
            increase_key(id,key,a,s);
            display(a,s);
        }
        else return 0;
    }
}