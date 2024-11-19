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
bool balance_check(node* n){
    int b_fact=balance_factor(n);
    if(b_fact>1 || b_fact<-1){
        return false;
    }
    return true;
}
void right_rotate(node *z){
    if(z==nullptr || z->left==nullptr) return;
    node* y=z->left;
    node* yr=y->right;
    if(z==root){
        root=y;
        y->parent=nullptr;
    }
    else{
        y->parent=z->parent;
        if(z->parent!=nullptr){
            if(z==z->parent->right){
                z->parent->right=y;
            }
            else{
                z->parent->left=y;
            }
        }
    }
    y->right=z;
    z->parent=y;
    z->left=yr;
    if(yr!=nullptr) yr->parent=z;
    updateheight(z);
    updateheight(y);
    //cout<<"right_rotate("<<z->data<<")"<<endl;
}
void left_rotate(node* z){
    if(z==nullptr || z->right==nullptr) return;
    node* y=z->right;
    node* yL=y->left;
    if(z==root){
        root=y;
        y->parent=nullptr;
    }
    else{
        y->parent=z->parent;
        if(z->parent!=nullptr){
            if(z==z->parent->left){
                z->parent->left=y;
            }
            else{
                z->parent->right=y;
            }
        }
    }
    y->left=z;
    z->parent=y;
    z->right=yL;
    if(yL!=nullptr){
        yL->parent=z;
    }
    updateheight(z);
    updateheight(y);
    //cout<<"left_rotate("<<z->data<<")"<<endl;
}
void display(node* root){
    if(root==nullptr) return ;
    display(root->left);
    cout<<root->data<<"("<<balance_factor(root)<<") ";
    display(root->right);
}
void balance(node* n,int x){
    
    if(!balance_check(n)){
        if(balance_factor(n)>1 && x<n->left->data){
            cout<<"Imbalance at node:  "<<n->data<<endl;
            cout<<"LL case"<<endl;
            cout<<"right_rotate("<<n->data<<")"<<endl;
            right_rotate(n);
        }
        else if(balance_factor(n)<-1 && x>n->right->data){
            cout<<"Imbalance at node:  "<<n->data<<endl;
            cout<<"RR case"<<endl;
            cout<<"left_rotate("<<n->data<<")"<<endl;
            left_rotate(n);
        }
        else if(balance_factor(n)>1 && x>n->left->data){
            cout<<"Imbalance at node:  "<<n->data<<endl;
            cout<<"LR case"<<endl;
            cout<<"left_rotate("<<n->left->data<<"), "<<"right_rotate("<<n->data<<")"<<endl;
            left_rotate(n->left);
            right_rotate(n);
        }
        else if(balance_factor(n)<-1 && x<n->right->data){
            cout<<"Imbalance at node:  "<<n->data<<endl;
            cout<<"RL case"<<endl;
            cout<<"right_rotate("<<n->right->data<<"), "<<"left_rotate("<<n->data<<")"<<endl;
            right_rotate(n->right);
            left_rotate(n);
        }
    
    }
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
    display(root);
    cout<<endl;
    if(balance_check(root)){
        cout<<"Balanced"<<endl;
        cout<<"Root="<<root->data<<endl;
    }
    else{
        node* temp=new_node;
        bool imbalanced=false;
        while(temp!=nullptr){
            if(!balance_check(temp)){
                imbalanced=true;
                balance(temp,x);
                
                break;
            }
            temp=temp->parent;
        }
        if(imbalanced){
            cout<<"Status:";
            display(root);
            cout<<endl;
            cout<<"Root="<<root->data<<endl;
        }
    }
    //return root;
}
int main(){
    int a;
    while(1){
        cin>>a;
        if(a==-1){
            cout<<"Status: ";
            display(root);
            cout<<endl;
            break;
        }
        else{
            insert(a);
        }
    }
}