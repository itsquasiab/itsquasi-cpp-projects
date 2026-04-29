// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "vacation"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll dp[arr][5];

struct itsquasi
{
    int a, b, c;
} a[arr];


int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].a >> a[i].b >> a[i].c;
    }
    dp[0][1] = dp[0][2] = dp[0][3] = 0;
    dp[1][1] = a[1].a;
    dp[1][2] = a[1].b;
    dp[1][3] = a[1].c;
    for (int i = 2; i <= n; ++i){
        dp[i][1] = max(dp[i - 1][2], dp[i - 1][3]) + a[i].a;
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][3]) + a[i].b;
        dp[i][3] = max(dp[i - 1][1], dp[i - 1][2]) + a[i].c;
    }
    cout << max({dp[n][1], dp[n][2], dp[n][3]});
    return 0;
}