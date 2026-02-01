//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1004, mod = 1e9, inf = LLONG_MIN;

ll ps[arr][arr];
ll n, m;

ll getsum(int x, int y){
    int x2 = x + m - 1;
    int y2 = y + m - 1;
    return ps[x2][y2] - ps[x-1][y2] - ps[x2][y-1] + ps[x-1][y-1];
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> ps[i][j];
            ps[i][j] += (ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1]);
        }
    }
    ll res = 0;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= m; ++j){
            res = max(res, getsum(i, j));
        }
    }
    cout << res;
    return 0;
}