#include <bits/stdc++.h>
using namespace std;

vector < vector < int > > tree;
vector < int > dist;
vector < bool > visited;


void dfs(int u , int parent = -1) {
    cout << u << " ";
    for(auto it : tree[u] ) {
        if(it != parent) {
            dfs(it , u);
        }
    }
}

int main() {

    int n;
    cin >> n;

    // tree should be resized.
    tree.resize(n+1);
    dist.resize(n+1 , 0);
    visited.resize(n+1 , false);
    // only n-1 nodes
    for(int i = 0; i < n-1; i++) {
        int x , y; 
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    
    dfs(1);
    
    cout << "\n";

}