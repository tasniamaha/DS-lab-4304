#include<iostream>
#include<deque>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x;
    deque<int> a;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    int i=0;
    while(a.size()>1){
        if(i%2==0){
            int b=a.front();
            a.pop_front();
            a.push_back(b);
            a.pop_front();
            
        }
        else{
            int b=a.front();
            a.pop_front();
            a.push_back(b);
            int c=a.front();
            a.pop_front();
            a.push_back(c);
            a.pop_front();
        }
        i++;
        
    }
    if(i%2==0){
        cout<<"Isharq "<<a.front()<<endl;
    }
    else{
        cout<<"Daiyan "<<a.front()<<endl;
    }
}