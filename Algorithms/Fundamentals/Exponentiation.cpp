// the same algorithm without using recursion 
#include<bits/stdc++.h>
using namespace std;
void Exponentiation(){
    long long  a,b;
    cin>>a>>b;
    long long res=1;
    while(b>0){
        if(b & 1){
            res=res*a;
        }
        a=a*a;
        b=b/2;
    }
    cout<<res<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Exponentiation();
}