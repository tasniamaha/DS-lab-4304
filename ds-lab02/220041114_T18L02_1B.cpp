#include<iostream>
using namespace std;
int front=-1,rear=0,s=0;

bool isempty(){
    return front==-1 ;
}
int size_deque(){
    return s;
}
void push_front(int ar[],int key,int m){
    if(size_deque()==m){
        cout<<"Overflow"<<endl;
        return ;
    }
    if(front==-1){
        front=rear=0;
    }
    
    else{
        front=(front-1+m)%m;
    }
    ar[front]=key;
    s++;
}
void push_back(int ar[],int key,int m){
    if(size_deque()==m){
        cout<<"Overflow"<<endl;
        return ;
    }
    if(front==-1){
        front=rear=0;
    }
    
    else{
        rear=(rear+1)%m;
    }
    ar[rear]=key;
    s++;
}
void pop_front(int ar[],int m){
    if(isempty()){
        cout<<"Underflow"<<endl;
        return ;
    }
    if(front==rear){
        front=rear=-1;
        
    }
    
    else{
        front=(front+1)%m;
    }
    s--;
}
void pop_back(int ar[],int m){
    if(isempty()){
        cout<<"Underflow"<<endl;
        return ;
    }
    if(front==rear){
        front=rear=-1;
    }
    
    else{
        rear = (rear-1+m)%m;
    }
    s--;
}

void display(int ar[],int m){
    if(isempty()){
        cout<<" "<<endl;
        return ;
    }
    else{
        int i=front;
        for(int j=0;j<s;j++){
            cout<<ar[i]<<" ";
            i=(i+1)%m;
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    string s;
    int ar[n];
    while(s!="E"){
        cin>>s;
        if(s=="PF"){
            int a;
            cin>>a;
            push_front(ar,a,n);
            display(ar,n);
        }
        else if(s=="PB"){
            int a;
            cin>>a;
            push_back(ar,a,n);
            display(ar,n);
        }
        else if(s=="DF"){
            pop_front(ar,n);
            if(!isempty()){
                display(ar,n);
            }
        }
        else if(s=="DB"){
            pop_back(ar,n);
            if(!isempty()){
                display(ar,n);
            }
        }
        else if(s=="S"){
            cout<<size_deque()<<endl;
            continue;
        }
        else if(s=="F"){
            cout<<front<<endl;
            continue;
        }
        else if(s=="R"){
            cout<<rear<<endl;
            continue;
        }
        else if(s=="STAT"){
            if(isempty()){
                cout<<"EMPTY"<<endl;
                continue;
            }
            else if(size_deque()==n){
                cout<<"FULL"<<endl;
                continue;
            }
            else{
                cout<<"NONE"<<endl;
                continue;
            }
        }
        else{
            break;
        }
        
    }
}