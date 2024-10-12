#include<iostream>
#include<string>
using namespace std;
struct node{
    int data;
    node* next=nullptr;
    node* prev=nullptr;
};
node *head=nullptr;
node *tail=nullptr;
bool isempty(){
    return head==nullptr && tail==nullptr;
}
node* createnode(int x){
    node* newnode=new node();
    newnode->data=x;
    newnode->next=nullptr;
    newnode->prev=nullptr;
    return newnode;
}
void insertbegin(int data) {
    node* new_node = createnode(data);
    if(isempty()){
        head = tail = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void insertback(int data){
    node* new_node= createnode(data);
    if(isempty()){
        head=tail=new_node;
    }
    else{
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
    }
    
}
void insertafter(int key,int v){
    //node* new_node= createnode(key);
    node* temp=head;
    while(temp!=nullptr && temp->data!=v){
        temp=temp->next;
    }
    if(temp!=nullptr){
        node* new_node= createnode(key);
        new_node->next=temp->next;
        new_node->prev=temp;
        temp->next=new_node;
        if(new_node->next!=nullptr){
            new_node->next->prev=new_node;
        }
        if(temp==tail){
            tail=new_node;
        }
    }
    else{
        cout<<"Value Not found"<<endl;
        return ;
    }
    
}
void update_node(int key,int v){
    node* temp=head;
    while(temp!=nullptr && temp->data!=v){
        temp=temp->next;
    }
    if(temp!=nullptr){
        temp->data=key;
    }
    else{
        cout<<"Value Not found"<<endl;
    }
}
void remove_head(){
    if(isempty()){
        cout<<"Underflow"<<endl;
        return ;
    }
    node* temp=head;
    head=head->next;
    if(head!=nullptr){
        head->prev=nullptr;
    }
    else{
        tail=nullptr;
    }
    delete temp;
}
void remove_back(){
    if(isempty()){
        cout<<"Underflow"<<endl;
        return ;
    }
    if(head->next==nullptr){
        remove_head();
        head=tail=nullptr;
        return ;
    }
    node* temp=tail;
    tail=tail->prev;
    tail->next=nullptr;
    delete temp;
}
void remove_element(int key){
    if(isempty()){
        cout<<"Value Not Found"<<endl;
        return;
    }
    if(head->data==key){
        remove_head();
        return ;
    }
    node* temp=head;
    while(temp!=nullptr  && temp->data!=key){
        temp=temp->next;
    }
    if(temp==nullptr){
        cout<<"Value Not Found"<<endl;
        return;
    }
    if(temp->next!=nullptr){
        temp->prev->next=temp->next;
    }
    else{
        tail=temp->prev;
    }
    if(temp->prev!=nullptr){
        temp->next->prev=temp->prev;
    }
    if(temp==tail){
        tail=temp->prev;
    }
    
    delete temp;
}
void display(){
    if(isempty()){
        cout<<"Empty"<<endl;
        cout<<"NULL (HEAD) (TAIL)"<<endl;
        return ;
    }
    cout<<head->data<<" (HEAD) ";
    node* temp=head->next;
    while(temp!=nullptr){
        cout << "-> " << temp->data << " ";
        temp = temp->next; 
    }
    cout<<"(TAIL)"<<endl;
}
int main(){
    string s;
    while(1){
        cin>>s;
        if(s=="INSERT_FRONT"){
            int a;
            cin>>a;
            insertbegin(a);
            display();
        }
        else if(s=="INSERT_BACK"){
            int a;
            cin>>a;
            insertback(a);
            display();
        }
        else if(s=="INSERT_AFTER"){
            int a,b;
            cin>>a>>b;
            insertafter(a,b);
            display();
        }
        else if(s=="UPDATE"){
            int a,b;
            cin>>a>>b;
            update_node(a,b);
            display();
        }
        else if(s=="REMOVE_HEAD"){
            remove_head();
            display();
        }
        else if(s=="REMOVE"){
            int a;
            cin>>a;
            remove_element(a);
            display();
        }
        else if(s=="REMOVE_TAIL"){
            remove_back();
            display();
        }
        else if(s=="EXIT"){
            break;
        }
        else{
            cout<<"invalid input"<<endl;
        }
    }
}
