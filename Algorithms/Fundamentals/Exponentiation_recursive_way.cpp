// the complexity of the function will be O(log n) 
// where the normal multiplication takes of complexity O(n)
#include<bits/stdc++.h>
using namespace std;

int binomial_power(int a,int b){
    if(b==0)
      return 1;
    else{
       int result = binomial_power(a,b/2);
       if(b % 2 == 0){
           return result*result;
       }
       else 
           return result*result*a;
    }
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<binomial_power(a,b)<<endl;
}