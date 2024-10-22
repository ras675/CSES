#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int color[MAXN];

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    color[start] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (color[v] == 0) {
                color[v] = 3 - color[u]; // Assign the opposite color
                q.push(v);
            } else if (color[v] == color[u]) {
                return false; // Two friends have the same color, impossible to divide into two teams
            }
        }
    }

    return true; // All pupils are successfully colored
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            if (!bfs(i)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << color[i] << " ";
    }
    cout << endl;

    return 0;
}
