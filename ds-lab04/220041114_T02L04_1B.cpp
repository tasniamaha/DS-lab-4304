#include<iostream>
using namespace std;
struct node{
    int data;
    node* next=nullptr;
    node* prev=nullptr;
};
node* createnode(int x){
    node* newnode=new node();
    newnode->data=x;
    newnode->next=nullptr;
    newnode->prev=nullptr;
    return newnode;
}
node* insertbegin(node* head, int data) {
    node* new_node = createnode(data);
    new_node->next = head;
    if (head != nullptr) {
        head->prev = new_node;
    }
}
