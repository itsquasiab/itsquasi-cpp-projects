// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "BYTESM2"

using namespace std;

const ll arr = 106, mod = 1e9 + 7;

ll a[arr][arr], dp[arr][arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int tsc;
    cin >> tsc;
    for (int c = 1; c <= tsc; ++c){
        int h, w;
        cin >> h >> w;
        for (int i = 1; i <= h; ++i){
            for (int j = 1; j <= w; ++j){
                cin >> a[i][j];
            }
        }
        for (int i = 0; i <= h; ++i){
            for (int j = 0; j <= w + 1; ++j){
                dp[i][j] = -1e18;
            }
        }
        for (int j = 1; j <= w; ++j){
            dp[1][j] = a[1][j];
        }
        for (int i = 2; i <= h; ++i){
            for (int j = 1; j <= w; ++j){
                dp[i][j] = max({dp[i - 1][j], dp[i - 1][j - 1], dp[i - 1][j + 1]}) + a[i][j];
                //cout << dp[i][j] << "\t";
            }
            //cout << "\n";
        }
        ll res = 0;
        for (int j = 1; j <= w; ++j){
            res = max(res, dp[h][j]);
        }
        cout << res << "\n";
    }
    return 0;
}