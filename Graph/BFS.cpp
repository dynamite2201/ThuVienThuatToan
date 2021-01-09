#include<iostream>
#include<queue>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> path;
vector<bool> visited;

void bfs(int s) {
    int sz = adj.size();
    path.assign(sz, -1);
    visited.assign(sz, false);
    queue<int> q;

    q.push(s);
    visited[s] = true;

    int u, v;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); ++i) {
            v = adj[u][i];
            if (!visited[v]) {
                visited[v] = true;
                path[v] = u;
                q.push(v);
            }
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;

    adj.assign(n + 1, vector<int>());
    for (int u, v, i = 0; u, v, i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    return 0;
}