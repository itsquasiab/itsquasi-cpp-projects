// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "redstone"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool matrix[506][506];
bool visited[506][506];

int n, m, k, q;

int visit_i[4] = {-1, 0, 1, 0};
int visit_j[4] = {0, 1, 0, -1};

int li = 0, lj = 0;

//visit_matrix[i][j], clockwise ordered

void matrix_explorer(int i, int j){
    matrix[i][j] = 1;
    visited[i][j] = 1;
    //cout << "current pos: " << i << " " << j << "\n";
    for (int way = 0; way <= 3; ++way){
        int ni = i + visit_i[way];
        int nj = j + visit_j[way];
        if (ni >= 1 && ni <= n && nj >= 1 && nj <= m){
            if (abs(li - ni) + abs(lj - nj) <= k && !visited[ni][nj]){
                //cout << "pos valid: [" << ni << "][" << nj << "]\n";
                matrix_explorer(ni, nj);
            }
        }
        //else cout << "pos not valid: [" << ni << "][" << nj << "]\n";
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
    cin >> n >> m >> k >> q;
    for (int idx = 1; idx <= q; ++idx){
        int x, y;
        cin >> x >> y;
        li = x, lj = y;
        matrix_explorer(x, y);
        ll cnt = 0;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                cnt += matrix[i][j];
                visited[i][j] = 0; // you have to keep this so that your code won't break
                //cout << matrix[i][j] << " ";
            }
            //cout << "\n";
        }
        cout << cnt << "\n";
    }
    return 0;
}