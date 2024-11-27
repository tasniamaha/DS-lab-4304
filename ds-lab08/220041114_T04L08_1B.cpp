#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<double>> a(n,vector<double>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>a[i][j];
        }
    }
    int ans=0;
    string s="";
    for(int i=0;i<n;i++){
        unordered_map<double,int> slope;
        int overlap=0,vertical=0,currmax=0;
        for(int j=i+1;j<n;j++){
            int dx=a[j][0]-a[i][0];
            int dy=a[j][1]-a[i][1];
            if(dx==0 && dy==0){
                overlap++;
            }
            else if(dy==0){
                s="y="+to_string(a[i][1]);
            }
            else if(dx==0){
                vertical++;
                s="x="+to_string(a[i][0]);;
            }
            else{
                double sl=(double)dx/dy;
                slope[sl]++;
                double intercept=a[i][1]-sl*a[i][0];
                currmax=max(currmax,slope[sl]);
                s="y="+to_string(sl)+"x "+(intercept<0?"-":"+")+to_string(intercept);
            }
        }
        ans=max(ans,max(currmax,vertical)+overlap+1);
    }
    cout<<s<<endl;
    cout<<ans<<endl;
    
}