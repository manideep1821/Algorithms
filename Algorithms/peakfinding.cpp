#include<bits/stdc++.h>
using namespace std;
int findpeak(int arr[],int low,int high,int size){
    int mid=(low + high)/2;
    if((mid==0 || arr[mid]>=arr[mid-1]) && (mid==size-1 || arr[mid]>=arr[mid+1]))  return mid;
    else if(mid>0 && arr[mid]<arr[mid+1]){
        return findpeak(arr, mid+1, high,size);
    }
    else return findpeak(arr,0,mid-1,size);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"the peak element is : "<<findpeak(arr,0,n-1,n)<<endl;
    return 0;
}