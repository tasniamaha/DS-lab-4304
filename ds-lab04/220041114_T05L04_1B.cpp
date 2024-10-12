#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};

node* createnode(int x){
    node* newnode=new node();
    newnode->data=x;
    newnode->next=nullptr;
    return newnode;
}
void insert_back(node*& head,int x){
    node* newnode=createnode(x);
    if(head==nullptr){
        head=newnode;
    }
    else{
        node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=createnode(x);
    }
}
node* intersect(node* list_1,node* list_2){
    node* h=nullptr;
    node* t=nullptr;
    while(list_1!=nullptr && list_2!=nullptr){
        if(list_1->data==list_2->data){
            if(h==nullptr){
                h=createnode(list_1->data);
                t=h;
            }
            else{
                t->next=createnode(list_1->data);
                t=t->next;
            }
            list_1=list_1->next;
            list_2=list_2->next;
        }
        else if(list_1->data<list_2->data){
            list_1=list_1->next;
        }
        else{
            list_2=list_2->next;
        }
    }
    return h;
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
    node* list1=nullptr;
    node* list2=nullptr;
    int a;
    while(1){
        cin>>a;
        if(a==-1) break;
        insert_back(list1,a);
    }
    int b;
    while(1){
        cin>>b;
        if(b==-1) break;
        insert_back(list2,b);
    }
    node* ans=intersect(list1,list2);
    display(ans);
}