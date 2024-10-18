#include<iostream>
#include<queue>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node* parent;
    int height;
};
node* root=nullptr;
void insert(int x){
    node* new_node=new node();
    new_node->data=x;
    new_node->left=new_node->right=new_node->parent=nullptr;
    new_node->height=0;
    node* temp=root;
    if(temp==nullptr){
        root=new_node;
    }
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
        
    }
}
node* lca(node* root,int n1,int n2){
    if(root->data<n1 && root->data<n2){
        return lca(root->right,n1,n2);
    }
    else if(root->data>n1 && root->data>n2){
        return lca(root->left,n1,n2);
    }
    else return root;
}
int main(){
    int n;
    cin>>n;
    int count=0;
    int val;
    while(count<n){
        cin>>val;
        insert(val);
        count++;
    }
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        node* n=lca(root,a,b);
        cout<<n->data<<endl;
    }
}