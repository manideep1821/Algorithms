// This implementation is a little simpler than the previous implementation based on the Sieve of Eratosthenes,
// however also has a slightly worse complexity O(nlogn)
// Here the sum is over all positive divisors d of n.
#include<bits/stdc++.h>
using namespace std;
void phi_1_to_n(){
    int n;
    cin>>n;
    vector<int>phi(n+1);
    phi[0]=0;
    phi[1]=1;
    for(int i=2;i<=n;i++)
       phi[i]=i;
    for(int i=2;i<=n;i++){
        if(phi[i]==i){
            for(int j=2*i;j<=n;j+=i){
                phi[j]-=phi[j];
            }
        }
    }
    cout<<phi[n]<<endl;
}
int main(){
    phi_1_to_n();
}