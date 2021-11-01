// the complexity of the algo is O(sqrt(n))
// Euler's totient function, also known as phi-function ϕ(n) 
#include<bits/stdc++.h>
using namespace std;
int phi(int n){
    int result=n;
    for(int i=2;i<=sqrt(n);i++){
        if(n % i ==0){
            while(n % i==0){
                n=n/i;
            }
        result-=result/i;
        }
    }
    if(n>1){
        result-=result/n;
    }
    return result;
}
int main(){
    int n ;
    cin >> n;
    cout<<"the number of coprime for "<<n << " between 1 to "<<n<<" are : "<<phi(n)<<endl;
    return 0;
}