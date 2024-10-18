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
void inorder(node* root){
    if(root==nullptr){
        return ;
    }
    else{
        inorder(root->left);
        cout<<root->data<<"(";
        if(root->parent==nullptr){
            cout<<"null) ";
        }
        else{
            cout<<root->parent->data<<") ";
        }
        inorder(root->right);
    }
}
void preorder(node* root){
    if(root==nullptr){
        return ;
    }
    cout<<root->data<<"(";
    if(root->parent==nullptr){
        cout<<"null) ";
    }
    else{
        cout<<root->parent->data<<") ";
    }
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    if(root==nullptr){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"(";
    if(root->parent==nullptr){
        cout<<"null) ";
    }
    else{
        cout<<root->parent->data<<") ";
    }
}
void levelorder(node* root){
    if(root==nullptr) return ;
    queue<node*> q;
    q.push(root);
    int level=1;
    while(!q.empty()){
        int nodecount=q.size();
        cout<<"Level "<<level<<": ";
        while(nodecount>0){
            node* currentnode=q.front();
            q.pop();
            if(currentnode->parent!=nullptr) cout<<currentnode->data<<"("<<currentnode->parent->data<<") ";
            else cout<<currentnode->data<<"(null) ";
            if(currentnode->left!=nullptr) q.push(currentnode->left);
            if(currentnode->right!=nullptr) q.push(currentnode->right);
            nodecount--;
        }
        cout<<endl;
        level++;
    }
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
    int b;
    while(1){
        cin>>b;
        switch(b){
            case 1:{
                inorder(root);
                cout<<endl;
                break;
            }
            case 2:{
                preorder(root);
                cout<<endl;
                break;
            }
            case 3:{
                postorder(root);
                cout<<endl;
                break;
            }
            case 4:{
                levelorder(root);
                break;
            }
            case 5: return 0;
        }
    }
}
