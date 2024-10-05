#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<int>a;
    int x;
    while(true){
        cin>>x;
        if(x==-1) break;
        a.push_back(x);
    }
    priority_queue<int,vector<int>,greater<int>> pq(a.begin(),a.end());
    int total=0;
    while(pq.size()>1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        int cost=a+b;
        total+=cost;
        pq.push(cost);
    }
    cout<<total<<endl;
}