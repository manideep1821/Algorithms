#include<bits/stdc++.h>
using namespace std;
const int N = 10000000;

int count_arr[N+1]={0}; // stores the minimum factor of each number . 
vector<int>ptr; // strores the prime numbers 

void seive(){
    count_arr[1]=1;
    for(int i=2;i<=N;i++){
        if(count_arr[i]==0){
            count_arr[i]=i;
            ptr.push_back(i);
        }
        for(int j=0;j<ptr.size() && ptr[j]<=count_arr[i] && i*ptr[j]<=N;j++){
            count_arr[i*ptr[j]]=ptr[j];
        }
    }
}
int main(){
    seive();
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        cout<<ptr[i]<<" ";  // gives first n prime numbers .
    }
    cout<<"\n";
    for(int i=0;i<=n;i++){
        cout<<count_arr[i]<<" ";  // gives minimum factor of first n numbers . 
    }
    cout<<"\n";
    return 0;
}