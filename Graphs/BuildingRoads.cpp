#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

const int INF = INT_MAX;

void dijkstra(vector<vector<pii> >& graph, vector<int>& distances, int start) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair(0, start));
    distances[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > distances[u]) continue;

        for (vector<pii>::iterator it = graph[u].begin(); it != graph[u].end(); ++it) {
            int v = it->first;
            int w = it->second;
            if (distances[u] + w < distances[v]) {
                distances[v] = distances[u] + w;
                pq.push(make_pair(distances[v], v));
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii> > graph(n + 1);
    vector<int> distances(n + 1, INF);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(make_pair(b, 1));
        graph[b].push_back(make_pair(a, 1));
    }

    int start = 1;
    dijkstra(graph, distances, start);

    vector<pair<int, int> > new_roads;
    for (int i = 2; i <= n; ++i) {
        if (distances[i] == INF) {
            new_roads.push_back(make_pair(start, i));
            dijkstra(graph, distances, i);
        }
    }

    cout << new_roads.size() << endl;
    for (vector<pair<int, int> >::iterator it = new_roads.begin(); it != new_roads.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
