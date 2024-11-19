#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
struct node{
    char data;
    node* left;
    node* right;
    node* parent;
    int height;
};
//node* root=nullptr;;
node* insert(const vector<char>& preorder,int& index){
    if(index>=preorder.size()||preorder[index]=='-'){
        index++;
        return nullptr;
    }
    node* newnode=new node{preorder[index++],nullptr,nullptr,nullptr,0};
    newnode->left=insert(preorder,index);
    newnode->right=insert(preorder,index);
    return newnode;
}
void inorder(node* root,vector<char>& in){
    //vector<char> in;
    if(root==nullptr) {
        in.push_back('-');
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
    
}
void postorder(node* root,vector<char>& post){
    //ector<char> post;
    if(root==nullptr) {
        post.push_back('-');
        return;
    }
    postorder(root->left,post);
   
    postorder(root->right,post);
    post.push_back(root->data);
    //return post;
}
int main(){
    string input;
    vector<char> pre;
    getline(cin,input);
    for(int i=0;i<input.length();i++){
        pre.push_back(input[i]);
    }
    int index=0;
    node* root=insert(pre,index);
    cout<<"Inorder:"<<endl;
    vector<char>intraverse;
    inorder(root,intraverse);
    for(int i=0;i<intraverse.size();i++){
        cout<<intraverse[i];
    }
    cout<<endl;
    vector<char>postraverse;
    postorder(root,postraverse);
    cout<<"Postorder:"<<endl;
    for(int i=0;i<postraverse.size();i++){
        cout<<postraverse[i];
    }
    cout<<endl;
}