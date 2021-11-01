// the array should be sorted one
// complexity average = o(log(n));
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n , k;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> k; //required number
    int first = 0, last = n - 1;
    while(first <= last){
        int mid = (last + first) / 2;
        if(arr[mid] == k){
            cout << "FOUND" <<endl; // stops when the number is found
            return 0;
        }
        else if(arr[mid] > k){
            last = mid - 1;
        }
        else if(arr[mid] < k){
            first = mid + 1;
        }
    }
    cout << "NOT FOUND" << endl;
}
