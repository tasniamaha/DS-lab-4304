#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* head=nullptr;
node* tail=nullptr;
bool isempty(){
    return head==nullptr && tail==nullptr;
}
node* createnode(int x){
    node* newnode=new node();
    newnode->data=x;
    newnode->next=nullptr;
    //newnode->prev=nullptr;
    return newnode;
}
void insertback(int data){
    node* new_node= createnode(data);
    if(isempty()){
        
        head=tail=new_node;
    }
    else{
        tail->next=new_node;
        //new_node->prev=tail;
        
    }
    tail=new_node;
    
}
node* rearrange(node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return head; 
    }
    node* odd=head;
    node* even=head->next;
    node* evenhead=even;
    while(even!=nullptr && even->next!=nullptr){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;

    }
    odd->next=evenhead;
    return head;
}
void display(node* head){
    if(head==nullptr){
        cout<<"Empty"<<endl;
        return;
    }
    else{
        node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}
int main(){
    //node* list=nullptr;
    int a;
    while(1){
        cin>>a;
        if(a==-1) break;
        insertback(a);
    }
    node* ans=rearrange(head);
    display(ans);
}