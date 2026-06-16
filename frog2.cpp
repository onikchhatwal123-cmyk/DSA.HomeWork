#include <bits/stdc++.h>
using namespace std;

int main() {
	 int n,k;
    cin>>n>>k;
    vector<int>dp(n+1,INT_MAX);
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   dp[0]=0;
   for(int i = 1; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            if(i - j >= 0) {
                dp[i] = min(dp[i],dp[i-j] + abs(arr[i] - arr[i-j]));
            }
        }
    }

    cout << dp[n-1] << endl;
}