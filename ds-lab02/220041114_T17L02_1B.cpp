#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
queue<int> q1,q2;
int s=0;
void push(int x){
    q2.push(x);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    s++;
    swap(q1,q2);
}
void pop(){
    if(q1.empty()){
        cout<<"Underflow"<<endl;
        return ;
    }
    q1.pop();
    s--;
}
int size(){
    return s;
}
bool isempty(){
    return q1.empty();
}
bool isfull(int maxq){
    return s==maxq;
}
void display(){
    queue<int> temp=q1;
    vector<int> elements;
    while(!temp.empty()){
        elements.push_back(temp.front());
        temp.pop();
    }
    for(int i=elements.size()-1;i>=0;i--){
        cout<<elements[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int x;
    cin>>x;
    
    while(1){
        string op;
        cin>>op;
        if(op=="push"){
            int b;
            cin>>b;
            if(isfull(x)){
                cout<<"Overflow"<<endl;
            }
            else{
                push(b);
            }
            display();
        }
        else if(op=="pop"){
            pop();
            display();
        }
        else if(op=="-1") break;
        
    }
}