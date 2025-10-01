//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = INT_MAX;

ll a[arr], dp[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dp[1] = 0;
    for (int i = 2; i <= n; ++i){
        dp[i] = inf;
        for (int j = i - 1; j >= i - t && j >= 1; --j){
            dp[i] = min({
                dp[i],
                dp[j] + abs(a[i] - a[j])
            });
        }
    }
    cout << dp[n];
    return 0;
}