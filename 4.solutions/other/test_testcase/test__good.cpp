//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

int n;
ll q;
ll a[arr], dp[arr];

ll r(ll a){
    return a - (a / 100 * q);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<ll>());
    dp[1] = r(a[1]);
    dp[2] = r(a[1] + a[2]);
    //dp[3] = a[1] + a[2] + a[3] - min({a[1], a[2], a[3]});
    for (int i = 3; i <= n; ++i){
        dp[i] = min({
            dp[i - 1] + r(a[i]),
            dp[i - 2] + r(a[i - 1] + a[i]),
            dp[i - 3] + a[i] + a[i - 1] + a[i - 2] - min({a[i], a[i - 1], a[i - 2]})
        });
    }
    cout << dp[n];
    return 0;
}