#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int dist[MAXN];
int parent[MAXN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    parent[start] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    memset(dist, -1, sizeof(dist));
    memset(parent, -1, sizeof(parent));

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);

    if (dist[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << dist[n] + 1 << endl;
        vector<int> path;
        for (int v = n; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
