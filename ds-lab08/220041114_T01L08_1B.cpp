#include<iostream>
#include<vector>
using namespace std;
int tablesize;
vector<int> table;
int num_element=0,choice;
int hash1(int x){
    return x%tablesize;
}
int hash2(int x){
    int r=7;
    return r-(x%r);
}
int probe(int i,int x){
    if(choice==1){
        return i;
    }
    else if(choice==2){
        return i*i;
    }
    else if(choice==3){
        return i*hash2(x);
    }
    return 0;
}
double load_factor(){
    return static_cast<double>(num_element)/tablesize;
}
void insert(int x){
    int init=hash1(x);
    for(int i=0;i<6;++i){
        int new_index=(init+probe(i,x))%tablesize;
        if(table[new_index]==-1){
            table[new_index]=x;
            num_element++;
            cout<<"Inserted : Index-"<<new_index<<" (L.F="<<load_factor()<<")"<<endl;
            return;
        }
        else{
            cout<<"Collision: Index-"<<new_index<<endl;
        }
    }
    cout<<"Input Abandoned"<<endl;
}
int main(){
    int inputcount;
    cin>>choice>>tablesize>>inputcount;
    table.assign(tablesize,-1);
    for(int i=0;i<inputcount;i++){
            int a;
            cin>>a;
            insert(a);
    }
        
    
    
}