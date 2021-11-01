#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    vector < int > dp(n+1 , 0);
    dp[0] = 1;
    for(int i = 1 ; i < n ; i++) {
        if(arr[i] > arr[i-1]) {
            dp[i] = dp[i-1] + 1;
        }
        else dp[i] = dp[i-1];
    }
    cout << *max_element(dp.begin() , dp.end()) << endl;
}