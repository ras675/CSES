#include<iostream>
#include<vector>

using namespace std;

int n,m;
vector<vector<char> > map;
vector<vector<bool> > visited;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

void dfs(int x,int y){
    visited[x][y]=true;

    for(int i=0;i<4;i++){
        int nx =  x + dx[i];
        int ny =  y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && map[nx][ny] == '.') {
            dfs(nx, ny);
        }
    }
}

int countRooms() {
    int rooms = 0;

    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && map[i][j] == '.') {
                dfs(i, j);
                rooms++;
            }
        }
    }

    return rooms;
}

int main(){

    cin >> n >> m;

     map.assign(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }

    cout << countRooms() << endl;

    return 0;
    
}