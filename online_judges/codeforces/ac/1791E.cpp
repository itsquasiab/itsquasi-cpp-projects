// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "1791E"

using namespace std;

const ll arr = 2e5 + 6, mod = 1e9 + 7;

ll a[arr];
ll dp[arr];

void solve(){
    int n;
    cin >> n;
    ll org_sum = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    dp[0] = 0;
    dp[1] = a[1];
    for (int i = 2; i <= n; ++i){
        dp[i] = max(dp[i - 1] + a[i], dp[i - 2] + a[i - 1] * -1 + a[i] * -1);
    }
    cout << dp[n] << "\n";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int tc;
    cin >> tc;
    while (tc--){
        solve();
    }
    return 0;
}