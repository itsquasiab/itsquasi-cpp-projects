// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "1639"

using namespace std;

const ll arr = 5006, mod = 1e9 + 7;

ll dp[arr][arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    string a, b;
    cin >> a >> b;
    for (int i = 0; i <= a.size(); ++i) dp[i][0] = i;
    for (int i = 0; i <= b.size(); ++i) dp[0][i] = i;
    for (int i = 1; i <= a.size(); ++i){
        for (int j = 1; j <= b.size(); ++j){
            dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])});
        }
    }
    cout << dp[a.size()][b.size()];
    return 0;
}