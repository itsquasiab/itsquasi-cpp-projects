// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <queue>
#define ll long long
#define task "vmunch"

using namespace std;

const ll arr = 106, mod = 1e9 + 7;

char grid[arr][arr];
bool visited[arr][arr];
ll cnt[arr][arr];
int n, m;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int sx, int sy){
    queue<pair<int,int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    cnt[sx][sy] = 1;

    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for (int direction = 0; direction < 4; ++direction){
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m){

                if (!visited[nx][ny] && (grid[nx][ny] == '.' || grid[nx][ny] == 'B')){
                    visited[nx][ny] = 1;
                    cnt[nx][ny] = cnt[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> m;
    int pos1, pos2;
    int pr1, pr2;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> grid[i][j];
            if (grid[i][j] == 'C') pos1 = i, pos2 = j;
            else if (grid[i][j] == 'B') pr1 = i, pr2 = j;
        }
    }
    cnt[pr1][pr2] = 1e6;
    if (!visited[pos1][pos2]){
        cnt[pos1][pos2] = 1;
        bfs(pos1, pos2);
    }
    /*for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cout << cnt[i][j] << "\t";
        }
        cout << "\n";
    }*/
    cout << cnt[pr1][pr2] - 1;
    return 0;
}