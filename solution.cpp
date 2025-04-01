#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
        
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>>final_state(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>final_state[i][j];
            }
        }
        vector<vector<char>> pres(n,vector<char>(m));
        for(int i=0;i<n;i++){
            if(pres[i][0]=='0'){
                if()
            }
        }
    }
    
}