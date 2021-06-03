#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+7; // upto 10 ^ 7 values

vector<bool>is_prime(N,true);

void seive(){
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=sqrt(N);i++){
        if(is_prime[i] && (long long)i*i<=N){
            for(int j= i*i;j<=N;j+=i){
                is_prime[j]=false;
            }
        } 
    }
}

int count (int n){
    int count=0;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            count++;
        }
    }
    return count;
}
int main(){
    seive();
    int n;
    cin>>n;
    cout<<"the number of prime numbers in range "<< n << " are : "<< count(n)<<endl;
    return 0;
}