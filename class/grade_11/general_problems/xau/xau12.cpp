// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "xau12"

using namespace std;

const ll arr = 3006, mod = 1e9 + 7;

ll dp[arr][arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    for (int i = 1; i <= n; ++i) dp[i][i] = 1;
    for (int k = 1; k < n; ++k){
        for (int i = 1; i <= n - k; ++i){
            int j = i + k;
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    cout << n - dp[1][n];
    return 0;
}