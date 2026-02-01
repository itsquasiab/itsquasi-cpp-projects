// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1'006, mod = 1'000'000'007;

int n, m;
string grid[arr];
bool visited[arr][arr];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (!visited[nx][ny] && grid[nx][ny] == 'B') {

            }
            if (!visited[nx][ny] && grid[nx][ny] == '.') {
                dfs(nx, ny);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i){
        cin >> grid[i];
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (grid[i][j] == 'A' && !visited[i][j]){
                dfs(i, j);
            }
        }
    }
    return 0;
}