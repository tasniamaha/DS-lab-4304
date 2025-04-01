#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<vector<int>> buildsparse(const vector<int>& a){
    int n=a.size();
    int max_log = floor(log2(n)) + 1;
    vector<vector<int>>sparse(n,vector<int>(max_log,0));
    for(int i=0;i<a.size();i++){
        sparse[i][0]=a[i];
    }
    for(int j=1;j<max_log;j++){
        for(int i=0;i + (1 << j) - 1 < n;i++){
            sparse[i][j]=max(sparse[i][j-1],sparse[i + (1 << j-1)][j-1]);
        }
    }
    return sparse;
}
int get_max(const vector<vector<int>>& sparse, int l, int r) {
    int len = r - l + 1;
    int j = floor(log2(len)); 
    return max(sparse[l][j], sparse[r - (1 << j) + 1][j]);
}
int main(){
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    vector<vector<int>> table=buildsparse(a);
    int count=0;
    
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        if (l == r) {
            count++;
            continue;
        }
        int max_between=0;
        if(r-l>1){
            max_between=get_max(table,l+1,r-1);
        }
        if(max_between<=a[l] ){
            count++;
        }
    }
    cout<<count<<endl;
}