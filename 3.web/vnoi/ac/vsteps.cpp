//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 14062008, inf = LLONG_MIN;

ll dp[arr];
bool save[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= t; ++i){
        ll a;
        cin >> a;
        save[a] = 1;
    }
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i){
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        if (save[i]) dp[i] = 0;
    }
    cout << dp[n];
    return 0;
}