// lowest commen ancestor
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

int lca (int x , int y , int LOG) {

    if(dist[x] < dist[y]) swap(x , y);

    int k = dist[x] - dist[y];

    // bringing x and y to same level

    for(int i = LOG-1; i >= 0; i--) {
        if(1LL & (k >> i)) x = up[x][i];
    }

    if(x == y) return x; // x will be lca

    // bringing them togethor

    for(int i = LOG-1; i >= 0; i --) {
        if(up[x][i] != up[y][i]) {
            x = up[x][i];
            y = up[y][i];
        }
    }

    return up[x][0];

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

    int x , y;
    cin >> x >> y;
    cout << "lca  : " << lca(x , y , val) << "\n"; 

}