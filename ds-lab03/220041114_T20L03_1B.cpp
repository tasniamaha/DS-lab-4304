#include<iostream>
using namespace std;
void insertlarge(int x,int k,int ar[]){
     if (x >ar[k - 1]) { 
        ar[k - 1] = x;
        for (int i = k - 1; i > 0; i--) {
            if (ar[i] > ar[i - 1]) {
                swap(ar[i], ar[i - 1]);
            } else {
                break;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int pref[n+1];
    pref[0]=0;
    for(int i=1;i<=n;i++){
        pref[i]=pref[i-1]+arr[i-1];
    }
    int klarge[k];
    for(int i=0;i<k;i++){
        klarge[i]=INT_MIN;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
           
            int x =pref[j] -pref[i - 1];
            insertlarge(x, k, klarge);
        }
    }
    cout<<klarge[k-1]<<endl;
}