// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "running"

using namespace std;

const ll arr = 1e4 + 6, mod = 1e9 + 7;

ll a[arr];
ll dp[arr][1006];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= m; ++j){
            if (j > 0 && j <= i) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i]);
            if (j < m && j <= i) dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        res = max(res, dp[i][0]);
    }
    /*cout << "\t";
    for (int i = 0; i <= m; ++i){
        cout << "[" << i << "]\t";
    }
    cout << "\n";
    for (int i = 1; i <= n; ++i){
        cout << "[" << i << "]\t";
        for (int j = 0; j <= m; ++j){
            cout << dp[i][j] << "\t";
        }
        cout << "\n";
    }*/
    cout << res << "\n";
    return 0;
}