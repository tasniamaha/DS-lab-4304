#include<iostream>

using namespace std;
int front=0,rear=0,count=0;
bool isempty(){
    return count==0 ;
}
bool isfull(int maxq){
    return count==maxq;
}

void enqueue(int x,int ar[],int maxq,int &count){
    if(count==maxq){
        cout<<"Overflow!!!"<<endl;
        
    }
    else{
        ar[rear]=x;
        rear=(rear+1)%maxq;
        count++;
    }
}
void dequeue(int arr[],int maxq,int &count){
    if(count==0){
        cout<<"Underflow!!!"<<endl;
        
    }
    else{
        front=(front+1)%maxq;
        count--;
    }
}
int size(){
    return count;
}
int retfront(int arr[]){
    return arr[front];
}
void display(int ar[],int maxq){
    if(isempty()){
        cout<<"-"<<endl;
        return ;
    }
    else{
        int i=front;
        for(int j=0;j<count;j++){
            cout<<ar[i]<<" ";
            i=(i+1)%maxq;
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    while(1){
        string c;
        cin>>c;
        if(c=="-1") break;
        else{
            if(c=="E"){
            int b;
            cin>>b;
            enqueue(b,a,n,count);
        }
        else{
            dequeue(a,n,count);
        }
        cout<<"Current size :"<<size()<<endl;
        cout<<"Full? :";
        if(isfull(n)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        cout<<"Empty? :";
        if(isempty()){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        if(isempty()){
            cout<<"Front Element : "<<"-"<<endl;
            cout<<"Front Index : "<<0<<endl;
            cout<<"Rear Element : "<<"-"<<endl;
            cout<<"Rear Index :"<<0<<endl;
        }
        else{
            cout<<"Front Element : "<<retfront(a)<<endl;
            cout<<"Front Index : "<<front<<endl;
        
            cout<<"Rear Element : "<<a[(rear - 1 + n) % n]<<endl;
            cout<<"Rear Index :"<<(rear - 1 + n) % n<<endl;
        }
        cout<<"Queue Elements :";
        display(a,n);
        
        }
    }
}