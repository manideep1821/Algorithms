#include<bits/stdc++.h>
using namespace std;
int GreatestCommmenDivisor(int n,int m){
    if(m==0) return n;
    else  return GreatestCommmenDivisor(m,n%m);
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<"gcd : "<<GreatestCommmenDivisor(n,m)<<endl;
    cout<<"lcm : "<<(n*m)/GreatestCommmenDivisor(n,m)<<endl;
    return 0;
}