// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
ll w, dp[arr];
pair<ll, ll> a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n >> w;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = w; j >= a[i].first; --j){
            dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);
        }
    }
    ll mx = 0;
    for (int i = 0; i <= w; ++i){
        mx = max(mx, dp[i]);
    }
    cout << mx;
    return 0;
}