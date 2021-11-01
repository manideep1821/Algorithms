// complexity if of O(log(n))
#include<bits/stdc++.h>
using namespace std;

int fact_power(int n , int k) {
    int res = 0;
    while(n) {
        n = n / k;
        res += n;
    }
    return res; // returns the max power of k which can divide the fact of n.
}

int main() {
    int n , k;
    cin >> n >> k;
    cout << fact_power(n,k) << endl;
    return 0;
}