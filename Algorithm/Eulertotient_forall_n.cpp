// the complexity of algorithm is O(nloglog(n))
// the eulertotient using Sieve of Eratosthenes caluclates for all the numbers from 1 to n
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
            for(int j=i;j<=n;j+=i){
                phi[j]-=phi[j]/i;
            }
        }
    }
    cout<<phi[n]<<endl;
}
int main(){
    phi_1_to_n();
}