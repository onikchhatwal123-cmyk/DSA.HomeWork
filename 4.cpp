#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n),ans(n,-1);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            if(v[j]>v[i]){
                ans[i]=v[j];
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << ans[i]<< " ";
    }
    return 0;
}