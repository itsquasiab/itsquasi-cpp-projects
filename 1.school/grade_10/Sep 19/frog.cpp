//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = INT_MAX;

ll dp[arr], a[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        dp[i] = inf;
    }
    dp[1] = 0;
    dp[2] = abs(a[2] - a[1]);
    for (int i = 3; i <= n; ++i){
        for (int j = i - 1; j >= max(i - t, 1); --j){
            dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
        }
    }
    cout << dp[n];
    return 0;
}