#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void max_heapify(int i,vector<int> &arr,int s){
    int l=2*i;
    int r=2*i+1;
    int largest=i;
    if(l<=s && arr[l]>arr[largest]){
        largest=l;
    }
    
    if(r<=s && arr[r]>arr[largest]){
        largest=r;
    }
    
    if(largest!=i){
        swap(arr[largest],arr[i]);
        max_heapify(largest,arr,s);
    }
}
void build_maxheap(vector<int> &arr,int s){
    for(int i=(s/2);i>=1;i--){
        max_heapify(i,arr,s);
    }
}
int heap_maximum(vector<int> &arr){
    return arr[1];
}
int extract_heap_max(vector<int> &arr,int &s){
    if(s<1){
        cout<<"Underflow"<<endl;
        return -1;
    }
    int m=arr[1];
    arr[1]=arr[s];
    s--;
    max_heapify(1, arr, s);
    return m;
}
void max_heap_insert(vector<int> &arr,int &s,int k){
    s++;
    arr.resize(s+1);
    arr[s]=k;
    int id=s;
    
    while(id>1){
        int parent=(id)/2;
        if(arr[parent]>=arr[id]) break;
        swap(arr[parent],arr[id]);
        id=parent; 
    }
}
void increase_key(int i,int k,vector<int> &arr,int &s){
    arr[i]+=k;
    max_heapify(i,arr,s);
}
void decrease_key(int i,int k,vector<int> &arr,int &s){
    arr[i]-=k;
    int id=s;
    max_heapify(i,arr,s);
}
void display(vector <int> &arr,int s){
    for(int i=1;i<=s;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int x;
    vector<int> a(1);
    while (1)
    {
       cin>>x;
       if(x==-1) break;
       a.push_back(x);
    }
    int s=a.size()-1;
    build_maxheap(a,s);
    cout<<"Max Heap: ";
    display(a,s);
    int b;
    while(1){
        cin>>b;
        if(b==1){
            cout<<heap_maximum(a)<<endl;
            display(a,s);
        }
        else if(b==2){
            cout<<extract_heap_max(a,s)<<endl;
            display(a,s);
        }
        else if(b==3){
            int key;
            cin>>key;
            max_heap_insert(a,s,key);
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