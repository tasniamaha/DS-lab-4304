#include<iostream>
using namespace std;
struct node{
    int data;
    node* prev;
    node* next;

};
node* head=nullptr;
node* tail=nullptr;
int s=0;
bool isempty(){
    return head==nullptr && tail==nullptr;
}
node* createnode(int x){
    node* newnode=new node();
    newnode->data=x;
    newnode->next=nullptr;
    newnode->prev=nullptr;
    return newnode;
}
void push_front(int data){
    node* new_node = createnode(data);
    if(isempty()){
        head = tail = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    s++;
}
void push_back(int data){
    node* new_node= createnode(data);
    if(isempty()){
        head=tail=new_node;
    }
    else{
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
    }
    s++;
}
int pop_front(){
    if(isempty()){
        cout<<"Underflow"<<endl;
        return -1;
    }
    int d=head->data;
    node* temp=head;
    head=head->next;
    if(head!=nullptr){
        head->prev=nullptr;
    }
    else{
        tail=nullptr;
    }
    delete temp;
    s--;
    return d;
}
int pop_back(){
    if(isempty()){
        cout<<"Empty"<<endl;
        return -1;
    }
    if(head==tail){
        head=tail=nullptr;
    }
    int d=tail->data;
    node* temp=tail;
    tail=tail->prev;
    tail->next=nullptr;
    delete temp;
    s--;
    return d;
}
int size(){
    return s;
}
void display(){
    if(isempty()){
        cout<<"Empty"<<endl;
        return ;
    }
    
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data <<" ";
        temp = temp->next; 
    }
    cout<<endl;
}

int main(){
    int a;
    while(1){
        cin>>a;
        switch(a){
            case 1:{
            int b;
            cin>>b;
            push_front(b);
            display();
            break;
            }
            case 2:{
            int c;
            cin>>c;
            push_back(c);
            display();
            break;
            }
            case 3:{
            int popped=pop_front();
            if(popped!=-1){
                display();
            }
            break;
            }
            case 4:{
            int poppedb=pop_back();
            if(poppedb!=-1){
                display();
            }
            break;
            }
            case 5:{
            cout<<size()<<endl;
            break;
            }
            case 6:{
            return 0;
            }
            default:{
            cout<<"Invalid input.Try again"<<endl;
            }
        }
    }
}