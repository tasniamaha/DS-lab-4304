#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int main(){
    int n;
    while(1){
        cin>>n;
        if(n==0) break;
        deque<int> a;
        for(int i=1;i<=n;i++){
            a.push_back(i);
        }
        vector<int> ar;
        while(a.size()>=2){
            int c=a.front();
            ar.push_back(c);
            a.pop_front();
            int b=a.front();
            a.pop_front();
            a.push_back(b);
           
        }
        cout<<"Discarded cards :";
        for(int i=0;i<ar.size();i++){
            cout<<ar[i];
            if(i<ar.size()-1){
                cout<<", ";
            }
        }

        cout<<endl;
        cout<<"Remaining Card :";
        if(!a.empty()){
            cout<<a.front()<<endl;
        }
    }
}