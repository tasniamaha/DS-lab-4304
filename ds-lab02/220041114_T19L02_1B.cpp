#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> std(n);
    vector<int> dishes(n);
    cout<<"Students = ";
    for(int i=0;i<n;i++){
        cin>>std[i];
    }
    cout<<"Dishes = ";
    for(int i=0;i<n;i++){
        cin>>dishes[i];
    }
    queue<int> students;
    stack<int> dish;
    for(int i=0;i<n;i++){
        students.push(std[i]);
    }
    for(int i=n-1;i>=0;i--){
        dish.push(dishes[i]);
    }
    int i=0;
    while(!students.empty() && !dish.empty()){
        if(students.front()==dish.top()){
            students.pop();
            dish.pop();
            i=0;
        }
        else{
            int a=students.front();
            students.pop();
            students.push(a);
            i++;
        }
        if(i>=n){
            break;
        }
    }
    cout<<students.size()<<endl;
}