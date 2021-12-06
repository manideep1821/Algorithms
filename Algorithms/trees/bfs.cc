#include <bits/stdc++.h>
using namespace std;

vector < vector < int > > tree;
vector < int > dist;
vector < bool > visited;


void bfs(int src) {
    queue < int > q;
    q.push(src);
    visited[src] = true;
    while(!q.empty()) {
        int top = q.front();
        cout << top << " ";
        q.pop();

        for(auto it : tree[top]) {
            if(!visited[it]) {
                dist[it] = dist[top] + 1;
                q.push(it);
                visited[it] = true;
            }
        }
    }
    cout << "\n";
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
    cout << "bfs order : ";

    bfs(1);
    
    for(int i = 1; i < 5; i++) cout << dist[i] << " ";
    cout << "\n";

}