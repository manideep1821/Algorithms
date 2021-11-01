#include <bits/stdc++.h>
using namespace std;

void buildtree(int segtree[] , vector < int > a , int s , int e , int index) {
    if(s == e) {
        segtree[index] = a[s];
        return ;
    }

    int mid = (s + e) / 2;

    buildtree(segtree , a , s , mid , 2*index);
    buildtree(segtree , a , mid+1 , e , 2*index + 1);

    segtree[index] = min(segtree[2*index] , segtree[2*index + 1]);
    // segtree[index] = max(segtree[2*index] , segtree[2*index + 1]);
    // segtree[index] = segtree[2*index] + segtree[(2*index) + 1];

    return ;
}

int query(int segtree[] , int s , int e , int qs , int qe , int index) {
    if(s >= qs && qe >= e) return segtree[index];
    if((qs < s && qe < s) || (qs > e && qe > e)) return INT_MAX;
    
    int mid = (s + e) / 2;

    int left = query(segtree , s , mid , qs , qe , 2*index);
    int right = query(segtree , mid+1 , e , qs , qe , (2*index) + 1);

    return min(left , right);
}

int main() {
    int t;
    cin >> t;
    vector < int > a;
    while(t != -1) {
        a.push_back(t);
        cin >> t;
    }
    int n = a.size();
    int segtree[4*n + 1];
    buildtree(segtree , a , 0 , n-1 , 1);
    
    int x , y;
    cin >> x >> y;
    while(x != -1 && y != -1) {
        int ans = query(segtree , 0 , n-1 , x , y , 1);
        cout << ans << endl;
        cin >> x >> y;
    }
}