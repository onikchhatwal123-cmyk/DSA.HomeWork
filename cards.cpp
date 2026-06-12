#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "enter:";
    cin >> n;

    vector<int>price(n);

    for(int i =0; i<n; i++){
        cin >> price[i];
    }

    for(int i=0; i<n; i++){
        int span = 1;

        for(int j=i-1; j>=0; j--){

            if(price[j] <= price[i]){
                span++;
            }
            else
            break;
        }

        cout << span << " ";
    }
}