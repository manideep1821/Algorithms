#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3000;

vector<bool>is_prime(N+1,true);
vector<int>count_factor(N+1,0);

void sieve(){
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=sqrt(N);i++){
        if(is_prime[i] && i*i<=N){
            for(int j= i*2;j<=N;j+=i){
                is_prime[j]=false;
                count_factor[j]++;
            } 
        }
    }
}
int count_val(int n){
    int count=0;
    for(int i=6;i<=n;i++){
        if(count_factor[i]==2){
            count++;
        }
    }
    return count;
}
int main(){
    sieve();
    int n;
    cin>>n;
    cout<<count_val(n);
}