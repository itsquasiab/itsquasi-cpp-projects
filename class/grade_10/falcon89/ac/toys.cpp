//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

ll a[arr], dp[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = n; i >= 1; --i){
        dp[i] = 0;
        ll s = 0;
        for (int x = 1; x <= 3 && i + x - 1 <= n; ++x){
            s += a[x + i - 1];
            dp[i] = max(dp[i], s + dp[i + 2 * x]);
        }
    }
    cout << dp[1];
    return 0;
}