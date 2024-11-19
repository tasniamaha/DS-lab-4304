#include<iostream>
#include<string>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node* parent;
    int height;
};
node* root=nullptr;
int height(node* n){
    if(n==nullptr){
        return 0;
    }
    else{
        return n->height;
    }
}
void updateheight(node* n){
    while(n!=nullptr){
        n->height=1+max(height(n->left),height(n->right));
        n=n->parent;
    }
}
int balance_factor(node* n)
{
    return height(n->left)-height(n->right);
}
void insert(int x){
    node* new_node=new node();
    new_node->data=x;
    new_node->left=new_node->right=new_node->parent=nullptr;
    new_node->height=1;
    node* temp=root;
    if(temp==nullptr) root=new_node;
    else{
        node* target=nullptr;
        while(temp!=nullptr){
            target=temp;
            if(new_node->data<temp->data){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
        new_node->parent=target;
        if(new_node->data<target->data) target->left=new_node;
        else target->right=new_node;
        updateheight(new_node);
    }
    
}
void display(node* root){
    if(root==nullptr) return ;
    display(root->left);
    cout<<root->data<<"("<<balance_factor(root)<<") ";
    display(root->right);
}
int main(){
    int a;
    while(1){
        cin>>a;
        if(a==-1) break;
        insert(a);
        display(root);
        cout<<endl;
    }
}