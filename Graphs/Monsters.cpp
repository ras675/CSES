#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> maze(n);
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    vector<vector<Point> > parent(n, vector<Point>(m, Point(-1, -1)));



    Point start;
    for (int i = 0; i < n; ++i) {
        cin >> maze[i];
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 'A') {
                start.x = i;
start.y = j;

                visited[i][j] = true;
            }
        }
    }

    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};
    const char direction[] = {'U', 'D', 'L', 'R'};

    queue<Point> q;
    q.push(start);

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (current.x == 0 || current.x == n - 1 || current.y == 0 || current.y == m - 1) {
            // Reached boundary square
            cout << "YES" << endl;
            
            // Reconstruct the path
            vector<char> path;
            while (maze[current.x][current.y] != 'A') {
                Point prev = parent[current.x][current.y];
                for (int i = 0; i < 4; ++i) {
                    if (prev.x + dx[i] == current.x && prev.y + dy[i] == current.y) {
                        path.push_back(direction[i]);
                        break;
                    }
                }
                current = prev;
            }
            cout << path.size() << endl;
            for (int i = path.size() - 1; i >= 0; --i) {
                cout << path[i];
            }
            cout << endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] != '#' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                parent[nx][ny] = current;
                Point nextPoint;
nextPoint.x = nx;
nextPoint.y = ny;
q.push(nextPoint);

            }
        }
    }

    // If BFS completes without reaching a boundary square
    cout << "NO" << endl;

    return 0;
}
