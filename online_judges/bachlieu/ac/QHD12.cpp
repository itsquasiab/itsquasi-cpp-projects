//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 13051984;

ll a[arr];
ll dp[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; ++i){
        ll brk;
        cin >> brk;
        a[brk] = -1;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i){
        if (a[i] == -1) continue;
        dp[i] = (dp[i - 1] + (i - 2 < 0 ? 0 : dp[i - 2])) % mod;
    }
    cout << dp[n];
    return 0;
}