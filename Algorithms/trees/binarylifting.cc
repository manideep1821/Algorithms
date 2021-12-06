// binary lifting
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector < vector < int > > tree;
vector < int > dist;

const int N = 100000;
const int maxval = 18;

int up[N][maxval]; // stores ancestors

void dfs(int u , int parent = -1) {

    for(auto it : tree[u]) {
        if(it != parent) {
            dist[it] = dist[u] + 1;
            up[it][0] = u;
            
            for(int i = 1; i < 18; i++) {
                up[it][i] = up[up[it][i-1]][i-1];  // (2 ^ i = 2 ^ (i-1) + 2 ^ (i-1))
            }

            dfs(it , u);
        }
    }
}

signed main() {
    int n;
    cin >> n;

    tree.resize(n+1);

    dist.resize(n+1);

    int val = log(n) + 1; // (max height of the tree  power of 2 );

    for(int i = 0; i < n-1; i ++) {
        int x , y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dfs(0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < val; j++) {
            cout << up[i][j] << " ";
        }
        cout << "\n";
    }

}