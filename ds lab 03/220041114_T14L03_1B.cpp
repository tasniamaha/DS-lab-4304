#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void max_heapify(int i,vector<int> &arr,int s){
    int l=2*i+1;
    int r=2*i+2;
    int smallest=i;
    if(l<s && arr[l]>arr[smallest]){
        smallest=l;
    }
    
    if(r<s && arr[r]>arr[smallest]){
        smallest=r;
    }
    
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        max_heapify(smallest,arr,s);
    }
}
void build_maxheap(vector<int> &arr,int s){
    for(int i=(s/2)-1;i>=0;i--){
        max_heapify(i,arr,s);
    }
}
int extract_heap_max(vector<int> &arr,int &s){
    if(s<0){
        cout<<"Underflow"<<endl;
    }
    int m=arr[0];
    arr[0]=arr[s-1];
    s--;
    max_heapify(0, arr, s);
    return m;
}
void changeheap(vector<int> &ar,int n){
    
    vector<int> temp(ar.begin(),ar.begin()+n);
    build_maxheap(temp,n);
    int a=extract_heap_max(temp,n);
    int b=extract_heap_max(temp,n);
    int c=extract_heap_max(temp,n);
    cout<<a*b*c<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int> ar(n);
    for(int i=0;i<n;i++){
        cin>>ar[i];
        if(i<2){
            cout<<"-1"<<endl;
        }
        else{
            changeheap(ar,n);
        }
    }
    
    
}