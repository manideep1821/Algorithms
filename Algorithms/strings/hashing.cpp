#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll N = 31;
ll mod = 1e9 + 9;
int main() {
    string a , b;
    cin >> a >> b;
    ll k = 0 , m = 0 , pow = 1;
    for(auto c : a) {
        k = (k + (c - 'a') * pow ) % mod;
        pow =  (pow * N) % mod;
    }
    pow = 1;
    for(auto c : b) {
        m = (m + (c - 'a') * pow ) % mod;
        pow =  (pow * N) % mod;
    }
    cout << k << endl <<  m << endl;
    if(k == m) cout << "YES" << endl;
    else cout << "NO" << endl;
}