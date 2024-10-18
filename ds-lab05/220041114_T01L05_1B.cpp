#include<iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node* parent;
    int height;
};
node* root=nullptr;
int getheight(node* n){
    if(n==nullptr){
        return -1;
    }
    else{
        return n->height;
    }
}
void updateheight(node* n){
    while(n!=nullptr){
        n->height=max(getheight(n->left),getheight(n->right))+1;
        n=n->parent;
    }
}
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
        updateheight(new_node);
    }
}
node* search(int value){
    node* n=root;
    while(n!=nullptr ){
        if(n->data==value){
            
            return n;
        }
        else if(n->data<value){
            n=n->right;
        }
        else{
            n=n->left;
        }
    }
    
    return nullptr;
}
void printsearch(node* found){
    if(found!=nullptr){
        cout<<"Present"<<endl;
        if(found->parent==nullptr){
            cout<<"Parent(null) ";
        }
        else{
            cout<<"Parent("<<found->parent->data<<") ";
        }
        if(found->left==nullptr){
            cout<<"Left(null) ";
        }
        else{
            cout<<"Left("<<found->left->data<<") ";
        }
        if(found->right==nullptr){
            cout<<"Right(null) "<<endl;;
        }
        else{
            cout<<"Right("<<found->right->data<<") "<<endl;;
        }
    }
    else{
        cout<<"Not Present"<<endl;
    }
    
}
void handleheight(int value){
    node* found=search(value);
    if(found!=nullptr){
        cout<<getheight(found)<<endl;
    }
    else{
        cout<<"Not present"<<endl;
    }
}
void inorder(node* root){
    if(root==nullptr){
        return ;
    }
    else{
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void before_after(int n){
    node* before=nullptr;
    node* after=nullptr;
    node* curr=root;
    while(curr!=nullptr){
        if(curr->data>n){
            after=curr;
            curr=curr->left;
        }
        else if(curr->data<n){
            before=curr;
            curr=curr->right;
        }
        else{
            if(curr->left!=nullptr){
                node* temp=curr->left;
                while(temp->right!=nullptr){
                    temp=temp->right;
                }
                before=temp;
            }
            if(curr->right!=nullptr){
                node* temp=curr->right;
                while(temp->left!=nullptr){
                    temp=temp->left;
                }
                after=temp;
            }
            break;
        }
    }
    if(before!=nullptr){
        cout<<before->data<<" ";
    }
    else{
        cout<<"null"<<" ";
    }
    if(after!=nullptr){
        cout<<after->data<<endl;
    }
    else{
        cout<<"null"<<endl;;
    }
}
int main(){
    int n;
    cin>>n;
    int count=0,x;
    
    while(count<n){
        cin>>x;
        count++;
        insert(x);
    }
    inorder(root);
    cout<<endl;
    int a;
    while(1){
        cin>>a;
        switch(a){
            case 3:{
                int b;
                cin>>b;
                node* found=search(b);
                printsearch(found);
                break;
            }
            case 4:{
                int c;
                cin>>c;
                handleheight(c);
                break;
            }
            case 5:{
                int d;
                cin>>d;
                before_after(d);
                break;
            }
            default:
            return 0;
        }
    }
}
