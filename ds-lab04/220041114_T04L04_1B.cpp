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
node *tail=nullptr;
node* createnode(int x){
    node* newnode=new node();
    newnode->data=x;
    newnode->next=nullptr;
    return newnode;
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
node* remove_duplicate(node*& head){
    if (head == nullptr || head->next == nullptr) {
        return head; 
    }
    node* temp=head;
    while(temp!=nullptr && temp->next!=nullptr){
        if(temp->data==temp->next->data){
            node* dup=temp->next;
            temp->next=temp->next->next;
            delete dup;
        }
        else{
            temp=temp->next;
        }
    }
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
        //cout<<"NULL"<<endl;
    }
}
int main(){
    //node* list1=nullptr;
    int a;
    while(1){
        cin>>a;
        if(a==-1) break;
        insert_back(a);
    }
    node* ans=remove_duplicate(head);
    display(ans);
}