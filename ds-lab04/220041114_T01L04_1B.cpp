#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define ll long long 
using namespace std;
struct node{
    int data;
    node *next;
};
node *head=nullptr;
node* tail=nullptr;
bool isempty(){
    return head==nullptr;
}
node* createnode(int x){
    node* newnode=new node();
    newnode->data=x;
    newnode->next=nullptr;
    return newnode;
}
void insert_front(int x){
    node* newnode=createnode(x);
    if(head==nullptr){
        head=tail=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}  
void insert_back(int x){
    node* newnode=createnode(x);
    if(head==nullptr){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
}
void insert_after_node(int x,int v){
    
    node* temp=head;
    while(temp!=nullptr && temp->data!=v){
        temp=temp->next;
    }
    if(temp!=nullptr){
        node* newnode=createnode(x);
        newnode->next=temp->next;
        temp->next=newnode;
        if(temp==tail){
            tail=newnode;
        }
    }
    else{
        cout<<"Value Not found"<<endl;
        return ;
    }
}
void update_node(int key,int v){
    node* temp=head;
    while(temp!=nullptr && temp->data!=v){
        temp=temp->next;
    }
    if(temp!=nullptr){
        temp->data=key;
    }
    else{
        cout<<"Value Not found"<<endl;
        return ;
    }
}
void remove_head(){
    if(head==nullptr){
        cout<<"Underflow"<<endl;
        return ;
    }
    node* temp=head;
    head=head->next;
    delete temp;
    if(head==nullptr) {
        tail=nullptr;
    }
}
void remove_back() {
    if (isempty()) {
        cout << "Underflow" << endl;
        return;
    }
    if (head==tail) { 
        delete head; 
        head=tail=nullptr; 
    } else {
        node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        delete tail;
        tail=temp;
        tail->next=nullptr;
    }
}
void remove_element(int key){
    if(isempty()){
        cout<<"Value Not Found"<<endl;
        return;
    }
    if(head->data==key){
        remove_head();
    }
    node* temp=head;
    
    while(temp!=nullptr && temp->next!=nullptr && temp->next->data!=key){
        temp=temp->next;
    }
    if(temp!=nullptr &&temp->next!=nullptr){
        node* toDelete=temp->next;
        temp->next=temp->next->next;
        if(toDelete==tail){
            tail=temp;
        }
        delete toDelete;
    }
    else{
        cout<<"Value Not found"<<endl;
        return ;
    }
}

void printlist() {
    if (isempty()) {
        cout <<"Head=Null, Tail=Null, Empty"<< endl;
        return;
    }
    cout<<"Head="<<head->data;
    
    if (tail!=nullptr) {
        cout <<", Tail=" << tail->data;
    cout << ", ";
    node* temp=head;
    while(temp!=nullptr) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    }
    cout<<endl;
}

int main(){
    int a;
    //cin>>a;
    while(true){
        cin>>a;
        switch(a){
            case 1:{
                int b;
                cin>>b;
                insert_front(b);
                printlist();
                break;
            }
            case 2:{
                int b;
                cin>>b;
                insert_back(b);
                printlist();
                break;
            }
            case 3:{
                int b,val;
                cin>>b>>val;
                insert_after_node(b,val);
                printlist();
                break;
            }
            case 4:{
                int b,val;
                cin>>b>>val;
                update_node(b,val);
                printlist();
                break;
            }
            case 5:{
                remove_head();
                printlist();
                break;
            }
            case 6:{
                int b;
                cin>>b;
                remove_element(b);
                printlist();
                break;
            }
            case 7:{
                remove_back();
                printlist();
                break;
            }
            case 8:{
                return 0;
            }
            default:{
                cout<<"Invalid input"<<endl;
                break;
            }
        }
    }
}