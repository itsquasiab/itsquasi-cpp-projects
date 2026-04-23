// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <iomanip>
#define ll long long
#define task "atcoder_dp_i"

using namespace std;

const ll arr = 3006, mod = 1e9 + 7;

long double a[arr], dp[arr];

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
        cin >> a[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i){
        for (int j = i; j >= 0; --j){
            dp[j] = dp[j] * (1.0 - a[i]) + (j > 0 ? dp[j - 1] * a[i] : 0.0);
        }
    }
    long double res = 0;
    for (int j = n / 2 + 1; j <= n; ++j){
        res += dp[j];
    }
    cout << fixed << setprecision(10) << res;
    return 0;
}