// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <queue>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int w, h, n;
ll k;
vector<vector<ll>> wh;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

queue<pair<int, int>> q;

void multi_bfs(){
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (wh[x][y] == 0) continue;

        for (int i = 0; i < 4; ++i){
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (x1 >= 0 && y1 >= 0 && x1 < w && y1 < h){
                if (wh[x1][y1] < wh[x][y] - 1){
                    wh[x1][y1] = wh[x][y] - 1;
                    q.push({x1, y1});
                }
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
    cin >> w >> h >> n >> k;
    wh.resize(w + 5);
    for (int i = 0; i < w; ++i){
        wh[i].resize(h + 5, 0);
    }
    for (int i = 1; i <= n; ++i){
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        if (wh[x][y] < k){
            wh[x][y] = k;
            q.push({x, y});
        }
    }
    multi_bfs();
    ll res = LLONG_MAX;
    for (int i = 0; i < w; ++i){
        for (int j = 0; j < h; ++j){
            res = min(res, wh[i][j]);
            //cout << wh[i][j] << " ";
        }
        //cout << "\n";
    }
    cout << res << "\n";
    return 0;
}