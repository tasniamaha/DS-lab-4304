#include <iostream>
using namespace std;
struct node {
    int data;
    node *next;
};

node* head=nullptr;  
int stacksize=0;     

node* createnode(int x) {
    node* newnode=new node();
    newnode->data = x;
    newnode->next = nullptr;
    return newnode;
}

bool isfull(int maxsize) {
    return stacksize==maxsize;
}

bool isempty() {
    return stacksize==0;
}

void push(int x,int n) {
    if (isfull(n)) {
        cout<<"Overflow"<<endl;
        return;
    }
    node* newnode=createnode(x);
    newnode->next=head;
    head=newnode;
    stacksize++;
}

void pop() {
    if(isempty()) {
        cout << "Underflow" << endl;
        return; 
    }
    node* temp=head;
    head=head->next;
    delete temp;
    stacksize--;
}

int peek() {
    if (isempty()) {
        cout<<"Stack is empty"<<endl;
        return -1; 
    }
    return head->data;
}

int size() {
    return stacksize;
}

void displayer(node* curr){
    if(curr==nullptr){
        return;
    }
    else{
        displayer(curr->next);
        cout<<curr->data<<" ";
    }
}
void printlist() {
    if (isempty()) {
        
        return;
    }
    displayer(head);
    cout<<endl;
}

int main() {
    int n;
    cin >> n;

    int a;
    while (true) {
        cin>>a;  
        if (a==-1) {
            break;
        } else {
            switch(a) {
                case 1:{
                    int b;
                    cin>>b;
                    push(b,n);
                    printlist();
                    break;
                }
                case 2:{
                    pop();
                    printlist();
                    break;
                }
                case 3:{
                    cout<<(isempty() ?"True":"False")<< endl;
                    break;
                }
                case 4:{
                    cout<<(isfull(n)?"True":"False")<<endl;
                    break;
                }
                case 5:{
                    cout<<size()<<endl;
                    break;
                }
                case 6:{
                    cout<<peek()<<endl;
                    break;
                }
                default:{
                    cout <<"Invalid input"<<endl;
                    break;
                }
            }
        }
    }
    
}
